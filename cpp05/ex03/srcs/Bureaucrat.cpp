/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:32 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 17:48:25 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Bureaucrat.hpp"
#include "../includes/display.hpp"

static void checkValue(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException(grade));
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException(grade)); 
}
//Constructors and destructors

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	display(getName() + " Bureaucrat constructor called", BLUE);
	std::cout << *this;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	checkValue(grade);
	_grade = grade;
	display(getName() + " Bureaucrat constructor called", BLUE);
	std::cout << *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src): _name(src.getName() + "_copy")
{
	*this = src;
	display(getName() + " Bureaucrat Copy constructor called", BLUE);
}
Bureaucrat::~Bureaucrat()
{
	display(getName() + " Bureaucrat destructor called", BLUE);
}

//assignment operator
Bureaucrat &Bureaucrat::operator= (Bureaucrat const& src)  
{
	_grade = src.getGrade();
	std::cout << *this;
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

//increment and decrement memeber functions
void	Bureaucrat::incrementGrade(void)
{
	try {
		checkValue(_grade - 1);
		_grade--;
		display("Dear " + getName() + " you've been promoted, congratulations! ", GREEN);
		std::cout << *this;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}

}
void	Bureaucrat::decrementGrade(void)
{
	try {
		checkValue(_grade + 1);
		_grade++;
		display("Dear " + getName() + " you can do better, keep going on! ", RED);
		std::cout << *this;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what() << " Value = " << e.getValue() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << "Exception caught: " << e.what()  << " Value = " << e.getValue() << std::endl ;
	}
}

void	Bureaucrat::signForm(AForm& form)
{
	int ret;
	
	try {
		ret = form.beSigned(*this);
		if (ret)
			display (getName() + " couldn't sign form " \
		+ form.getName() + " because " + ", form is already signed.", RED);
		else
			display(getName() + " signed " + form.getName(), GREEN);
	}
	catch (AForm::GradeTooLowException &e){
		display(getName() + " couldn't sign form " + form.getName() + " because " + e.what(), RED);
	}
}
void Bureaucrat::executeForm(AForm &form) const
{
	try {
		form.execute(*this);
		display(getName() + " executed " + form.getName(), GREEN);
	}
	catch (AForm::GradeTooLowException &e){
		display(getName() + " couldn't execute form " + form.getName() + " because " + e.what(), RED);
	}
}

//operator << overload
std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " <<  rhs.getGrade() << std::endl;
	return (os);
}