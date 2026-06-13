/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:57 by jodde             #+#    #+#             */
/*   Updated: 2026/06/13 16:51:53 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./DPmergeMe.hpp"
#include "./VPmergeMe.hpp"


static void displayArg(std::string arg)
{
	std::cout << " arg received [";
	for (std::string::iterator it = arg.begin(); it != arg.end(); ++it)
		std::cout << *it;
	std::cout << "]" << std::endl;
}	

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (logError("args : enter a sequence of positive integers "), 1);
	displayArg(argv[1]);
	VPmergeMe sortVec(argv[1]);
	sortVec.displayVec();
	return (0);
}