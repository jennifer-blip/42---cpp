/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:26:58 by jodde             #+#    #+#             */
/*   Updated: 2026/06/04 23:13:15 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>
#include <string>
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
		std::map<std::string, int> 	_exchangeRate;
		bool						validDate(std::string date);
		bool						validValue(int value);
		bool						validRate (double rate);
	
	public:
		//constructors and destructors
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& src);
		~BitcoinExchange();
		//assignment operator
		BitcoinExchange& operator=(BitcoinExchange const& rhs);
		//member functions
		void	importDatabase(std::string dataFilename);
		void	calcBtc(std::string filename);
}