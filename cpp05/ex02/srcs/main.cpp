/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 17:52:48 by jodde            ###   ########.fr       */
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
	
	display("====Testing FORM INITIALIZATION====", BROWN);
	display("=PresidentialPardonForm(sign 25, exec 5)=", BROWN);
	AForm *a = new PresidentialPardonForm("all TIG"); 
	display("=RobotomyRequestForm(sign 72, exec 45)=", BROWN);
	AForm *b = new RobotomyRequestForm("Xavier Niel");
	display("=ShrubberyCreationForm(sign 145, exec 137)=", BROWN);
	AForm *c = new ShrubberyCreationForm("Home");
	
	display("====Testing FORM SIGNATURE AUTHORIZATION====", BROWN);
	display("=Employee(45) sign PresidentialPardonForm=", BROWN);
	Employee.signForm(*a);
	display("=Employee(45) sign RobotomyRequestForm=", BROWN);
	Employee.signForm(*b);
	display("=Employee(45) sign ShrubberyCreationForm=", BROWN);
	Employee.signForm(*c);
	display("=BigBoss(1) sign PresidentialPardonForm=", BROWN);
	BigBoss.signForm(*a);
	display("=BigBoss(1) sign RobotomyRequestForm=", BROWN);
	BigBoss.signForm(*b);
	display("=BigBoss(1) sign ShrubberyCreationForm=", BROWN);
	BigBoss.signForm(*c);
	display("=Intern(150) sign PresidentialPardonForm=", BROWN);
	Intern.signForm(*a);
	display("=Intern(150) sign RobotomyRequestForm=", BROWN);
	Intern.signForm(*b);
	display("=Intern(150) sign ShrubberyCreationForm=", BROWN);
	Intern.signForm(*c);
	display("====Testing FORM EXECUTION AUTHORIZATION====", BROWN);
	display("=Employee(45) execute PresidentialPardonForm=", BROWN);
	Employee.executeForm(*a);
	display("=Employee(45) execute RobotomyRequestForm=", BROWN);
	Employee.executeForm(*b);
	display("=Employee(45) execute ShrubberyCreationForm=", BROWN);	
	Employee.executeForm(*c);
	display("=BigBoss(1) execute PresidentialPardonForm=", BROWN);
	BigBoss.executeForm(*a);
	display("=BigBoss(1) execute RobotomyRequestForm=", BROWN);
	BigBoss.executeForm(*b);
	display("=BigBoss(1) execute ShrubberyCreationForm=", BROWN);
	BigBoss.executeForm(*c);
	display("=Intern(150) execute PresidentialPardonForm=", BROWN);
	Intern.executeForm(*a);
	display("=Intern(150) execute RobotomyRequestForm=", BROWN);
	Intern.executeForm(*b);
	display("=Intern(150) execute ShrubberyCreationForm=", BROWN);
	Intern.executeForm(*c);
	delete a;
	delete b;
	delete c;
	return 0;
}