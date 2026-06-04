/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:27:37 by jodde             #+#    #+#             */
/*   Updated: 2026/06/04 23:12:53 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "./BitcoinExchange.hpp"

DEFINE DATA_FILENAME "data.csv"

void	display(std::string msg, color col)
{
	switch (col)
	{
		case (RED):
		{
			std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BROWN):
		{
			std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (GREEN):
		{
			std::cout << "\033[32m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BLUE):
		{
			std::cout << "\033[34m" << msg << "\033[0m" << std::endl;
			break;
		}		
		default :
			std::cout << msg << std::endl;
	}
}

void	logError(std::string message)
{
	display("ERROR -" + message, RED);
}

int	checkFormat(std::fstream& fs)
{
	std::string buf[100];
	
	getline(fs, buf, '\n');
	{
		size_t	pos;
		if ((pos=buf.find("date", 0)) == std::string::npos || 
			(pos=buf.find("|", pos)) == std::string::npos ||
			(pos=buf.find("value", pos)) == std::string::npos)
			return (logError("expected table format : 'date | value'"), 0)
		buf.erase(0, 100);
	}
	while(!(fs.eof))
	{
		getline(fs, buf, '\n');
		{
			
		}
		//split "date | value"
		//check arg = valid date format ("Year-Month-Day")
		//check arg = valid value format ("0-1000")
	
	}
}
std::fstream&	checkArgs(std::string Filename)
{
	std::fstream& fs;
	fs.open(Filename);
	if (fs.is_open())
	{
		if (!checkFormat(fs))
			return (nullptr);
	}	
	return (logError("could not open file"), nullptr);
	
}

int	main (int argc, char **argv)
{	
	if (argc < 2)
		return (logError("expected ARGS : <data filename>"), 1);
	BitcoinExchange btc;
	btc.importDatabase(DATA_FILENAME);
	btc.calcBtc(argv[1].c_str());
	return (0);
}