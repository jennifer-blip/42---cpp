/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:36:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/12 14:52:02 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

static void	checkGrade(int grade)
{
	if (grade > 150)
		throw (AForm::GradeTooLowException(grade));
}
//constructors and destructors
RobotomyRequestForm::RobotomyRequestForm(std::string Target) : AForm("RobotomyRequest", 72, 45), _target(Target)
{
	display(getName() + " Form constructor called", BLUE);
	std::cout << "\033[34m" << *this << "\033[0m" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm(src), _target(src._target)
{
	*this = src;
	display(getName() + " Form copy constructor called", BLUE);
	std::cout << "\033[34m" << *this << "\033[0m" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	display(getName() + " Form destructor called", BLUE);
}
//assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) 
{
	AForm::operator=(src);
	_target = src.getTarget();
	return (*this);
}
//accessors
std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

//member functions		
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static int	count = 0;

	checkGrade(executor.getGrade() - getExecGrade() + 150);
	if (getIsSigned())
	{
		display ("...some drilling noise...", GREEN);
		if (!(count % 2))
			display (getTarget() + " has been robotomized successfully", GREEN);
		else
			display (getTarget() + " robotomy failed", GREEN);
		count++;
	}
	else
		display (getTarget() + " robotomy failed because the form is not signed", GREEN);
}

//operator<< overload
std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &rhs)
{
	os << rhs.getName() << ", Form required sign grade " <<  rhs.getSignGrade() <<" required execution grade " << rhs.getExecGrade() \
	<< " - Form status: " << (rhs.getIsSigned() ? "signed" : "not signed") << " target: " << rhs.getTarget() << std::endl;
	return (os);
}