/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:57 by jodde             #+#    #+#             */
/*   Updated: 2026/06/27 14:17:25 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./DPmergeMe.hpp"
#include "./PmergeMe.hpp"


static void displayArg(char **argv, int argc)
{
	std::cout << " arg received [";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << "]" << std::endl;
}	

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (logError("args : enter a sequence of positive integers "), 1);
	std::string arg;
	displayArg(argv, argc);
	for (int i = 1; i < argc; i++)
		arg += std::string(" ", 1) + argv[i];
	PmergeMe<std::vector> vec(arg);
	vec.displayNum();
	PmergeMe<std::deque> deq(arg);
	deq.displayNum();
	return (0);
}