/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 17:29:04 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
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
		display("===Creating bureaucrat ===", BROWN);
		Bureaucrat a(argv[1], grade);
		display("===Incrementing grade===", BROWN);
		a.incrementGrade();
		display("===Incrementing grade===", BROWN);
		a.incrementGrade();
		display("===Decrementing grade===", BROWN);
		a.decrementGrade();
		display("===Decrementing grade===", BROWN);
		a.decrementGrade();
		display("===Incrementing grade===", BROWN);
		a.incrementGrade();
	}

	catch (Bureaucrat::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	std::cout << std::endl;
	display("===Copy constructor test===", BROWN);
	Bureaucrat a("BigBoss", 1);
	Bureaucrat b = a;
	std::cout << std::endl;
	display("===Default constructor test===", BROWN);
	Bureaucrat c;
	std::cout << std::endl;
	display("===Decrementing bureaucrat c grade===", BROWN);
	c.decrementGrade();
	std::cout << std::endl;
	display("===Assignment operator test===", BROWN);
	c = b;
	std::cout << std::endl;
	display("===Incrementing bureaucrat c grade===", BROWN);
	c.incrementGrade();
	return 0;
}