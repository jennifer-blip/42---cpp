/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/11 16:02:30 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bureaucrat.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <sstream>
#include <string>

int is_number(const std::string& grade, int *value)
{
	std::istringstream 	iss(grade);
	
	return (iss >> std::noskipws >> *value && iss.eof());
}

int	valid_arg(int argc, char **argv)
{
	int	value;

	if (argc < 3 || !(is_number(argv[2], &value)))
		return (-1);
	std::cout << value <<std::endl;
	return (value);	
}

int	main(int argc, char **argv)
{
	int grade;
	
	grade = valid_arg(argc, argv);
	if (grade < 0)
	{
		display("ERROR - invalid args : enter name and grade [1-150] of the bureaucrat", RED);
		return (0);
	}
	try {
		if (grade < 1)
			throw (-1);
		if (grade > 150)
			throw ('e');
		Bureaucrat a(argv[1], grade);
		std::cout << a;	
	}
	catch (int e){
		std::cout << "Exception caught: " << "grade too low" << std::endl ;
	}
	catch (char e){
		std::cout << "Exception caught: " << "grade too high" << std::endl ;
	}
	return 0;
}