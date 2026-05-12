/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/12 17:29:51 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <sstream>
#include <string>


int	main(void)
{
	Bureaucrat BigBoss("BigBoss", 1);
	std::cout << BigBoss;
	Bureaucrat Employee("Employee", 45);
	std::cout << Employee;	
	Bureaucrat Intern("Intern", 150);
	std::cout << Intern;
	
	display("Testing FORM INITIALIZATION", BROWN);
	AForm *a = new PresidentialPardonForm("RNCP7 validation"); 
	AForm *b = new RobotomyRequestForm("Xavier Niel");
	AForm *c = new ShrubberyCreationForm("Home");
	
	display("Testing FORM SIGNATURE AUTHORIZATION", BROWN);
	Employee.signForm(*a);
	Employee.signForm(*b);
	Employee.signForm(*c);
	BigBoss.signForm(*a);
	BigBoss.signForm(*b);
	BigBoss.signForm(*c);
	Intern.signForm(*a);
	Intern.signForm(*b);
	Intern.signForm(*c);
	Employee.executeForm(*a);
	Employee.executeForm(*b);	
	Employee.executeForm(*c);
	BigBoss.executeForm(*a);
	BigBoss.executeForm(*b);
	BigBoss.executeForm(*c);
	Intern.executeForm(*a);
	Intern.executeForm(*b);
	Intern.executeForm(*c);
	delete a;
	delete b;
	delete c;
	return 0;
}