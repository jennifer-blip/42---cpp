/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:26:58 by jodde             #+#    #+#             */
/*   Updated: 2026/06/11 21:22:14 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

enum color
{
	RESET,
	RED,
	BROWN,
	GREEN,
	BLUE
};

class BitcoinExchange
{
	private:
		std::map<std::string, double> 	_exchangeRate;
		bool						_validDate(std::string date);
		bool						_validRate (double& rate);
	
	public:
		//constructors and destructors
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& src);
		~BitcoinExchange();
		//assignment operator
		BitcoinExchange& operator=(BitcoinExchange const& rhs);
		//member functions
		void	importDatabase(const std::string& dataFilename);
		void	calcBtc(const std::string& filename);
		void	displayData(void);
		std::pair<std::string, double>	parseData(std::string& line, char sep);
};

void	logError(std::string message);