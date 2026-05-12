/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:36:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/12 17:22:37 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

static void	checkGrade(int grade)
{
	if (grade < 0)
		throw (AForm::GradeTooLowException(grade));
}
//constructors and destructors
PresidentialPardonForm::PresidentialPardonForm(std::string Target) : AForm("PresidentialPardon", 25, 5), _target(Target)
{
	display(getName() + " Form constructor called", BLUE);
	std::cout << "\033[34m" << *this << "\033[0m" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm(src), _target(src._target)
{
	*this = src;
	display(getName() + " Form copy constructor called", BLUE);
	std::cout << "\033[34m" << *this << "\033[0m" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	display(getName() + " Form destructor called", BLUE);
}
//assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) 
{
	AForm::operator=(src);
	_target = src.getTarget();
	return (*this);
}
//accessors
std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}
//member functions		

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkGrade(getExecGrade() - executor.getGrade() + 1);
	display (getTarget() + " has been pardoned by Zaphod Beeblebrox", GREEN);
}
//operator<< overload
std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &rhs)
{
		os << rhs.getName() << ", Form required sign grade " <<  rhs.getSignGrade() <<" required execution grade " << rhs.getExecGrade() \
		<< " - Form status: " << (rhs.getIsSigned() ? "signed" : "not signed") << " target: " << rhs.getTarget() << std::endl;
		return (os);
}