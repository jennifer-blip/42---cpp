/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanchen <hanchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:58:37 by hanchen           #+#    #+#             */
/*   Updated: 2026/04/19 00:48:02 by hanchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other){
	if (this != &other)
		_db = other._db;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database: " + filename);
	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t comma = line.find(',');
		if (comma == std::string::npos) continue;
		std::string date = line.substr(0, comma);
		std::string value = line.substr(comma + 1);
		if (!isValidDate(date)) continue;
		std::istringstream iss(value);
		double	rate;
		if (!(iss >> rate)) continue;
		_db[date] = rate;
	}
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open input file: " + filename);
	std::string line;
	if (!std::getline(file, line))
    	throw std::runtime_error("empty input file");
	if (line != "date | value")
    	throw std::runtime_error("invalid header");
	while (std::getline(file, line))
	{
		if (line.empty()) continue;
		size_t sep = line.find(" | ");
		if (sep == std::string::npos){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		std::string value = line.substr(sep + 3);
		if (!isValidDate(date)){
			std::cerr << "Error: bad date => " << date << std::endl;
			continue;
		}
		double amount = 0;
		if (!isValidValue(value, amount))
			continue;
		try
		{
			double rate = getRate(date);
			std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

/*
suppose the date is mar29, and the database has mar28, mar30, then lower_bound will return mar30, 
but we need mar28, so we check if the returned date is the same as the input date, 
if not, we move the iterator back by one step to get the closest previous date. 
If the iterator is already at the beginning, it means the input date is too early and we throw an error.
*/
double BitcoinExchange::getRate(const std::string &date) const
{
	if (_db.empty())
		throw std::runtime_error("database is empty");
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
	if (it == _db.end() || it->first != date){
		if (it == _db.begin())
			throw std::runtime_error("date too early: " + date);
		--it;
	}
	return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	for (int i = 0; i < 10; i++){
		if (i == 4 || i == 7) continue;
		if (!isdigit(date[i])) return false;
	}
	int	year = atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;
	int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (leap)
		daysInMonth[2] = 29;
	if (day > daysInMonth[month])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &str, double& out) const
{
	if (str.empty()) return false;
	std::istringstream iss(str);
	double	val;
	char	leftover;
	if (!(iss >> val)) return false;
	if (iss >> leftover) return false;
	if (val < 0)
	{
		std::cerr << "Error: not a postive number." << std::endl;
		return false;
	}
	if (val > 1000){
		std::cerr << "Error: too large value." << std::endl;
		return false;
	}
	out = static_cast<double>(val);
	return true;
}