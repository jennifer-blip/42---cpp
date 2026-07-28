/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:27:37 by jodde             #+#    #+#             */
/*   Updated: 2026/06/11 20:30:36 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "./BitcoinExchange.hpp"

# define REF_FILENAME "data.csv"

int	main (int argc, char **argv)
{	
	if (argc < 2)
		return (logError("expected ARGS : <data filename>"), 1);
	(void) argv;
	BitcoinExchange btc;
	btc.importDatabase(REF_FILENAME);
	// btc.displayData();
	btc.calcBtc(argv[1]);
	return (0);
}
