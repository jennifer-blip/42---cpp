/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:26:25 by jodde             #+#    #+#             */
/*   Updated: 2026/06/12 20:26:42 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>

void	logError(std::string message)
{
	std::string msg = "ERROR -" + message;
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange const& src){
	*this = src;
}
BitcoinExchange::~BitcoinExchange(){}

//assignment operator
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs){
	_exchangeRate = rhs._exchangeRate;
	return (*this);
}

static void	trimSpaces(std::string& str)
{
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
}

//member functions
std::pair<std::string, double>	BitcoinExchange::parseData(std::string& line, char sep)
{
	size_t			pos;
	std::string		date;
	double			rate;
	pos = line.find(sep);
	if (pos == std::string::npos)
		return (std::pair<std::string, double>());
	date = line.substr(0, pos);
	trimSpaces(date);
	if (!_validDate(date))
		throw (std::runtime_error("invalid date format"));
	std::string value = line.substr(pos + 1);
	trimSpaces(value);
	std::istringstream is(value);
	if (!(is >> rate))
		throw (std::runtime_error("invalid value"));
	if (rate == 0)
		rate = 0;
	if (sep == '|')
		_validRate(rate);
	return(std::pair<std::string, double>(date, rate));
}
void	BitcoinExchange::importDatabase(const std::string& dataFilename)
{
	std::string buf;
	std::ifstream fs(dataFilename.c_str());
	if (!fs.is_open())
			return (logError("could not open data file"));
	std::getline(fs, buf, '\n');
	while (std::getline(fs, buf, '\n'))
	{
		try {
			if (buf.empty())
				continue;
			std::pair <std::string, double> currentPair = parseData(buf, ',');
			_exchangeRate[currentPair.first] = currentPair.second;
		}
		catch (std::exception& e) { std::cerr << e.what() << std::endl;}
	}
}
void	BitcoinExchange::calcBtc(const std::string& filename)
{
	std::string buf;
	std::ifstream fs(filename.c_str());
	if (!fs.is_open())
			return (logError("could not open input file"));
	std::getline(fs, buf, '\n');
	if (buf != "date | value")
		return (logError("expected table format : 'date | value'"));
	while (std::getline(fs, buf, '\n'))
	{
		try {
			if(buf.empty())
				continue;
			std::pair <std::string, double> currentPair = parseData(buf, '|');
			std::map <std::string, double>::iterator it = _exchangeRate.lower_bound(currentPair.first);
			if (it == _exchangeRate.end() || it->first != currentPair.first)
			{
				if (it == _exchangeRate.begin())
					throw (std::runtime_error("no exchange rate available for this date"));
				--it;
			}
			std::cout << currentPair.first << " => " << currentPair.second << " = " << currentPair.second * it->second << std::endl;
		}
		catch (std::exception& e) {std::cerr << e.what() << std::endl;}
	}
}
void	BitcoinExchange::displayData(void)
{
	std::map<std::string, double>::iterator it;
	for (it = _exchangeRate.begin(); it != _exchangeRate.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

bool	BitcoinExchange::_validDate(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int Y;
	int M;
	int	D;
	std::istringstream isy(date.substr(0, 4));
	std::istringstream ism(date.substr(5, 2));
	std::istringstream isd(date.substr(8, 2));
	if (!(isy >> Y) || !(ism >> M) || !(isd >> D))
		return (false);
	if (D < 1 || M < 1 || Y < 0)
		return (false);
	if (M > 12 || ((M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) && D > 31))
		return (false);
	bool isLeap = (Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0;
	if ((M == 2 && D > (isLeap ? 29 : 28)) || ((M == 4 || M == 6 || M == 9 || M == 11) && D > 30))
		return (false);
	return (true);
}

void	BitcoinExchange::_validRate (double rate)
{
	if (rate < 0)
		throw (std::runtime_error("Error: not a positive number."));
	if (rate > 1000)
		throw (std::runtime_error("Error: too large a number."));
}
