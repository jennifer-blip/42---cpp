/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:32 by jodde             #+#    #+#             */
/*   Updated: 2026/05/11 16:02:05 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bureaucrat.hpp"
#include "../includes/display.hpp"


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	display(" Bureaucrat constructor called", BLUE);
}
Bureaucrat::Bureaucrat(Bureaucrat const& src): _name(src.getName() + "_copy")
{
	*this = src;
	std::cout << getName();
	display(" Bureaucrat Copy constructor called", BLUE);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << getName();
	display(" Bureaucrat destructor called", BLUE);
}

//assignment operator
Bureaucrat &Bureaucrat::operator= (Bureaucrat const& src)  
{
	_grade = src.getGrade();
	return (*this);
}
//accessors
int			Bureaucrat::getGrade(void) const
{
	return (_grade);
}
std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

//operator << overload
std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " <<  rhs.getGrade() << std::endl;
	return (os);
}