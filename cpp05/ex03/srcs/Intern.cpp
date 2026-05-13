/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:03:53 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 13:15:23 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

static int	checkName(std::string Name)
{
	std::string formName [3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	for (int i = 0; i < 3; i++)
	{
		if (!Name.compare(formName[i]))
			return(i);
	}
	throw (Intern::FormDoesNotExistException(Name));
}

static AForm	*createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}
static AForm	*createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
//constructors and destructor
Intern::Intern()
{
	display("Intern default constructor called", BLUE);
	std::cout << *this;
}
Intern::Intern(Intern& src)
{
	*this = src;
	display("Intern copy constructor called", BLUE);
	std::cout << *this;
}
Intern::~Intern()
{
	display("Intern destructor called", BLUE);
}
//Assignment operator
Intern& Intern::operator=(Intern const &src)
{
	(void) src;
	return(*this);	
}

//Member Function
AForm* Intern::makeForm(std::string FormName, std::string Target)
{
	int idx = 0;
	typedef AForm* (*FormCreator)(std::string);
	FormCreator funcTab [3] = {createPresidential, createRobotomy, createShrubbery};
	
	try{
		idx = checkName(FormName);
		AForm *a = funcTab[idx](Target);
		return (a);
	}
	catch (Intern::FormDoesNotExistException &e){
		std::cout << "Exception caught" << e.what() << " Name = " << e.getName() << std::endl;
	}
	return (NULL);
}

//operator= overload
std::ostream& operator<<(std::ostream& os, Intern const & rhs)
{
	(void) rhs;
	static int nb = 0;
	
	std::cout << "This is intern nb " << nb << " all you can ask him/her is to createForm('FormName', 'Target')" << std::endl;
	std::cout<< " he/she doesn't have a name and don't even know his/number"<< std::endl;
	return (os);
}