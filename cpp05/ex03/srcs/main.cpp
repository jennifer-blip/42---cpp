/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 13:16:51 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
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
	Bureaucrat Manager("Manager", 25);
	std::cout << Manager;	
	Bureaucrat Employee("Employee", 75);
	std::cout << Employee;	
	Intern intern;
	
	display("====Testing INTERN FORM CREATION====", BROWN);
	display("=PresidentialPardonForm(25)=", BROWN);
	AForm *a = intern.makeForm("PresidentialPardon", "all TIG"); 
	display("=RobotomyRequestForm(72)=", BROWN);
	AForm *b = intern.makeForm("RobotomyRequest", "Xavier Niel");
	display("=ShrubberyCreationForm(145)=", BROWN);
	AForm *c = intern.makeForm("ShrubberyCreation", "Home");
	
	display("====Testing FORM SIGNATURE AUTHORIZATION====", BROWN);
	display("=Manager(25) sign PresidentialPardonForm=", BROWN);
	Manager.signForm(*a);
	display("=Manager(25) sign RobotomyRequestForm=", BROWN);
	Manager.signForm(*b);
	display("=Manager(25)sign ShrubberyCreationForm=", BROWN);
	Manager.signForm(*c);
	display("=BigBoss(1) sign PresidentialPardonForm=", BROWN);
	BigBoss.signForm(*a);
	display("=BigBoss(1) sign RobotomyRequestForm=", BROWN);
	BigBoss.signForm(*b);
	display("=BigBoss(1) sign ShrubberyCreationForm=", BROWN);
	BigBoss.signForm(*c);
	display("=Employee(75)sign PresidentialPardonForm=", BROWN);
	Employee.signForm(*a);
	display("=Employee(75) sign RobotomyRequestForm=", BROWN);
	Employee.signForm(*b);
	display("=Employee(75) sign ShrubberyCreationForm=", BROWN);
	Employee.signForm(*c);
	display("====Testing FORM EXECUTION AUTHORIZATION====", BROWN);
	display("=Manager(25) execute PresidentialPardonForm=", BROWN);
	Manager.executeForm(*a);
	display("=Manager(25) execute RobotomyRequestForm=", BROWN);
	Manager.executeForm(*b);
	display("=Manager(25) execute ShrubberyCreationForm=", BROWN);	
	Manager.executeForm(*c);
	display("=BigBoss(1) execute PresidentialPardonForm=", BROWN);
	BigBoss.executeForm(*a);
	display("=BigBoss(1) execute RobotomyRequestForm=", BROWN);
	BigBoss.executeForm(*b);
	display("=BigBoss(1) execute ShrubberyCreationForm=", BROWN);
	BigBoss.executeForm(*c);
	display("=Employee(75) execute PresidentialPardonForm=", BROWN);
	Employee.executeForm(*a);
	display("=Employee(75) execute RobotomyRequestForm=", BROWN);
	Employee.executeForm(*b);
	display("=Employee(75) execute ShrubberyCreationForm=", BROWN);
	Employee.executeForm(*c);
	delete a;
	delete b;
	delete c;
	return 0;
}