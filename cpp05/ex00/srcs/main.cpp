/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/08 20:40:36 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

void checkValue (int grade)
{
	if (grade <= 0 || grade > 150){
		throw WrongValueException(grade);
	}
	else
		return;
}

int	valid_arg(int argc, std::string grade)
{
	int	result;
	
	if (argc < 4)
		return (-1);
	std::istringstream iss(grade);
	iss>>result;
	return (result);	
}

int	main(int argc, char **argv)
{
	int grade;
	
	grade = valid_arg(argc, argv[1]);
	if (grade < 0)
		return ("ERROR - invalid args : enter name and grade [1-150] of the bureaucrat");
	try {
		checkValue(grade);
	}
	catch (WrongValueException &e){
		std::cout << "Exception caught: " << e.what() << " Value = " <<e.getValue() << endl ;
	}
	Bureaucrat(argv[1], argv[2]);	
	return 0;
}