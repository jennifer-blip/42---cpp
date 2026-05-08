/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:32 by jodde             #+#    #+#             */
/*   Updated: 2026/05/08 20:45:15 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

//fonction d'affichage
static void print(std::string str, bool color)
{
	if (color)
		std::cout << GREEN << str << RESET << std::endl;
	else
    	std::cout << str << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	print(" Bureaucrat constructor called", true);
}
Bureaucrat::Bureaucrat(Bureaucrat const& src)
{
	*this = src;
	std::cout << getName();
	print(" Bureaucrat Copy constructor called", true);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << getName();
	print(" Bureaucrat destructor called", true);
}

//assignment operator
Bureaucrat Bureaucrat::operator= (Bureaucrat const& src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_grade = src.getGrade();
	}
	return (*this);
}
//accessors
int			Bureaucrat::getGrade const()
{
	return (_grade);
}
std::string	Bureaucrat::getName const()
{
	return (_name);
}