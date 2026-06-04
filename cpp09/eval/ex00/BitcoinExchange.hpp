#pragma once
#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadDatabase(const std::string &filename);
	void processInput(const std::string &filename) const;

private:
	std::map<std::string, double> _db;
	double getRate(const std::string &date) const;
	bool isValidDate(const std::string &date) const;
	bool isValidValue(const std::string &value, double& out) const;
};
