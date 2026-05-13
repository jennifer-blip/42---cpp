/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:58:49 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 13:15:13 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "../includes/AForm.hpp"


class	Intern
{
	public:
		//Constructors and destructor
		Intern();
		Intern(Intern& src);
		~Intern();
		//Assignment operator
		Intern& operator=(Intern const &src);
		//Member Function
		AForm* makeForm(std::string FormName, std::string Target);	
		//exceptions
		class	FormDoesNotExistException : public std::exception
		{
			private:
				std::string _name;
			
			public:
				FormDoesNotExistException(std::string Name) : _name(Name){}
				virtual ~FormDoesNotExistException() throw() {}
				virtual const char *what() const throw () {return("Form does not exist ([PresidentialPardon], [RobotomyRequest], [ShrubberyCreation])");}
				std::string getName (void) const { return (_name);}
		};
};

std::ostream& operator<<(std::ostream& os, Intern const & rhs);