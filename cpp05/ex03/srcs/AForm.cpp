/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:51:08 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 10:49:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

static void	checkGrade(int grade)
{
	if (grade < 1)
		throw (AForm::GradeTooLowException(grade));
	if (grade > 150)
		throw (AForm::GradeTooHighException(grade)); 
}
//constructors and destructors
AForm::AForm(): _name("default"), _signed(0), _signGrade(1), _execGrade(1)
{
	display(getName() + " AForm default constructor called", BLUE);
	//std::cout << "\033[34m" << *this << "\033[0m" << std::endl;
}

AForm::AForm(std::string Name, int SignGrade, int ExecGrade) : _name(Name), _signed(0), _signGrade(SignGrade), _execGrade(ExecGrade)
{
	checkGrade(SignGrade);
	checkGrade(ExecGrade);
	display(getName() + " AForm constructor called", BLUE);
	//std::cout << "\033[34m" << *this << "\033[0m" << std::endl;
}
AForm::AForm(const AForm& src): _name(src._name + "_copy"), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
	display(getName() + " AForm copy constructor called", BLUE);
}
AForm::~AForm()
{
	display(getName() + " AForm destructor called", BLUE);
}
//assignment operator
AForm& AForm::operator=(const AForm& src)
{
	setSigned(src.getIsSigned());
	return (*this);
}
//accessors
std::string AForm::getName() const
{
	return (_name);
}

bool		AForm::getIsSigned() const
{
	return(_signed);
}

void		AForm::setSigned(bool status)
{
	_signed = status;
}
int			AForm::getSignGrade() const
{
	return (_signGrade);
}
int			AForm::getExecGrade() const
{
	return (_execGrade);
}

//member functions		
int	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (getIsSigned())
	{
		return (1);
	}
	else{
		checkGrade(getSignGrade() - bureaucrat.getGrade() + 1);
		setSigned(1);
		return (0);
	}
}
//operator<< overload
std::ostream &operator<<(std::ostream &os, AForm const &rhs)
{
	os << rhs.getName() << ", Form required sign grade " <<  rhs.getSignGrade() <<" required execution grade " << rhs.getExecGrade() \
	<< " - Form status: " << (rhs.getIsSigned() ? "signed" : "not signed") << std::endl;
	return (os);
}