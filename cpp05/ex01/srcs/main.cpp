/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/11 21:01:31 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <sstream>
#include <string>


int	main(void)
{
	Bureaucrat a("BigBoss", 1);
	std::cout << a;
	Bureaucrat b("Employee", 150);
	std::cout << b;	
	
	display("Testing FORM EXCEPTIONS at initialization", BROWN);
	try {
		Form a1("Vacation1", 5, 10);
		std::cout << a1;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Form::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	try {
		Form a2("Vacation2", 0, 10);
		std::cout << a2;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Form::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	try {
		Form a3("Vacation3", 10, 0);
		std::cout << a3;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Form::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}	
	
	display("Testing FORM SIGNATURE AUTHORIZATION", BROWN);
	Form a4("Vacation4", 5, 10);
	std::cout << a4;
	a.signForm(a4);
	a4.setSigned(0);
	std::cout << a4;
	b.signForm(a4);
	Form a1("Vacation5", 150, 10);
	std::cout << a1;
	a.signForm(a1);
	a1.setSigned(0);
	b.signForm(a1);
	return 0;
}