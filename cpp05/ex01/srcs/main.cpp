/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 17:10:10 by jodde            ###   ########.fr       */
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
	Bureaucrat b("Employee", 150);	
	
	std::cout << std::endl;
	display("===Testing FORM EXCEPTIONS at initialization===", BROWN);
	display("==Creating Vacation1 form, signGrade: 5, execGrade: 10", BROWN);
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
	display("==Creating Vacation2 form, signGrade: 0, execGrade: 150", BROWN);
	try {
		Form a2("Vacation2", 0, 150);
		std::cout << a2;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Form::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	display("==Creating Vacation2 form, signGrade: 151, execGrade: 1", BROWN);
	try {
		Form a2("Vacation2", 151, 1);
		std::cout << a2;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Form::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	display("==Creating Vacation3 form, signGrade: 150, execGrade: 0", BROWN);
	try {
		Form a3("Vacation3", 150, 0);
		std::cout << a3;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Form::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}	
	display("==Creating Vacation3 form, signGrade: 1, execGrade: 151", BROWN);
	try {
		Form a3("Vacation3", 1, 151);
		std::cout << a3;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Form::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	std::cout << std::endl;
	display("===Testing FORM SIGNATURE AUTHORIZATION===", BROWN);
	display("==testing Vacation1 form", BROWN);
	Form a1("Vacation1", 5, 10);
	std::cout << a1;
	display("==testing Vacation1 form signature with Employee", BROWN);
	b.signForm(a1);
	display("==testing Vacation1 form signature with BigBoss", BROWN);
	a.signForm(a1);
	display("==testing Vacation4 form", BROWN);
	Form a4("Vacation4", 1, 10);
	std::cout << a4;
	display("==testing Vacation4 form signature with BigBoss", BROWN);
	a.signForm(a4);
	display("==testing Vacation4 form signature with Employee", BROWN);
	std::cout << a4 << "Form isSigned initialisation" << std::endl;
	a4.setSigned(0);
	std::cout << a4;
	b.signForm(a4);
	display("==testing Vacation5 form", BROWN);
	Form a5("Vacation5", 150, 10);
	std::cout << a5;
	display("==testing Vacation5 form signature with Employee", BROWN);
	a.signForm(a5);
	display("==testing Vacation5 form signature with BigBoss", BROWN);
	std::cout << a5 << "Form isSigned initialisation" << std::endl;
	a5.setSigned(0);
	std::cout << a5;
	b.signForm(a5);
	return 0;
}