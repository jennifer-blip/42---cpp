/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:51:08 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 17:06:14 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

static void	checkGrade(int grade)
{
	if (grade > 150)
		throw (Form::GradeTooLowException(grade));
	if (grade < 1)
		throw (Form::GradeTooHighException(grade)); 
}
//constructors and destructors
Form::Form(std::string Name, int SignGrade, int ExecGrade) : _name(Name), _signed(0), _signGrade(SignGrade), _execGrade(ExecGrade)
{
	checkGrade(SignGrade);
	checkGrade(ExecGrade);
	display(getName() + " Form constructor called", BLUE);
}
Form::Form(const Form& src): _name(src._name + "_copy"), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
	display(getName() + " Form copy constructor called", BLUE);
}
Form::~Form()
{
	display(getName() + " Form destructor called", BLUE);
}
//assignment operator
Form& Form::operator=(const Form& src)
{
	setSigned(src.getIsSigned());
	return (*this);
}
//accessors
std::string Form::getName() const
{
	return (_name);
}

bool		Form::getIsSigned() const
{
	return(_signed);
}

void		Form::setSigned(bool status)
{
	_signed = status;
}
int			Form::getSignGrade() const
{
	return (_signGrade);
}
int			Form::getExecGrade() const
{
	return (_execGrade);
}

//member functions		
int	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (getIsSigned())
	{
		return (1);
	}
	else{
		checkGrade(bureaucrat.getGrade() - getSignGrade() + 150);
		setSigned(1);
		return (0);
	}
}
//operator<< overload
std::ostream &operator<<(std::ostream &os, Form const &rhs)
{
	os << rhs.getName() << ", Form required sign grade " <<  rhs.getSignGrade() <<" required execution grade " << rhs.getExecGrade() \
	<< " - Form status: " << (rhs.getIsSigned() ? "signed" : "not signed") << std::endl;
	return (os);
}