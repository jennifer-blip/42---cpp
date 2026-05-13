/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:36:38 by jodde             #+#    #+#             */
/*   Updated: 2026/05/12 14:52:02 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "../includes/ShrubberyCreationForm.hpp"

static void	checkGrade(int grade)
{
	if (grade > 150)
		throw (AForm::GradeTooLowException(grade));
}
//constructors and destructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm("ShrubberyCreation", 145, 137), _target(Target)
{
	display(getName() + " Form constructor called", BLUE);
	std::cout << "\033[34m" << *this << "\033[0m" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm(src), _target(src._target)
{
	*this = src;
	display(getName() + " Form copy constructor called", BLUE);
	std::cout << "\033[34m" << *this << "\033[0m" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	display(getName() + " Form destructor called", BLUE);
}
//assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	AForm::operator=(src);
	_target = src.getTarget();
	return (*this);
}
//accessors
std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

//member functions		
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkGrade(executor.getGrade() - getExecGrade() + 150);
	if (getIsSigned())
	{
		std::ofstream	outfile((getTarget() + "_shrubbery").c_str());
		if (outfile.is_open())
		{
			outfile << "       _-_" << std::endl;
			outfile << "    /~~   ~~\\" << std::endl;
			outfile << " /~~         ~~\\" << std::endl;
			outfile << "{               }" << std::endl;
			outfile << " \\  _-     -_  /" << std::endl;
			outfile << "   ~  \\\\ //  ~" << std::endl;
			outfile << "_- -   | | _- _" << std::endl;
			outfile << "  _ -  | |   -_" << std::endl;
			outfile << "      // \\\\" << std::endl;
			outfile.close();
			display("A shrubbery file has been created, check the current directory", GREEN);
		}
		else
			display("Error: could not create file", RED);
	}
	else
		display("Form is not signed, cannot execute", RED);
}

//operator<< overload
std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &rhs)
{
	os << rhs.getName() << ", Form required sign grade " <<  rhs.getSignGrade() <<" required execution grade " << rhs.getExecGrade() \
	<< " - Form status: " << (rhs.getIsSigned() ? "signed" : "not signed") << " target: " << rhs.getTarget() << std::endl;
	return (os);
}