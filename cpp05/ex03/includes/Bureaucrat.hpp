/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:41 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 16:28:16 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include "../includes/display.hpp"
#include "../includes/AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		//conctructors and destructors
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		~Bureaucrat();
		//assignment operator
		Bureaucrat& operator= (Bureaucrat const& src);
		//accessors
		int			getGrade(void) const;
		std::string	getName(void) const;
		//member functions
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(AForm& form);
		void 	executeForm(AForm &form)const;
		//custom exceptions
		class GradeTooHighException : public std::exception
		{
			private:
				int	_value;
			
			public:
				GradeTooHighException (int grade) : _value(grade) {}
				virtual const char *what() const throw () {return("Grade too high!");}
				int getValue (void) const { return (_value);}
		};

		class GradeTooLowException : public std::exception
		{
			private:
				int	_value;
			
			public:
				GradeTooLowException (int grade) : _value(grade) {}
				virtual const char *what() const throw (){return("Grade too low!");}
				int getValue (void) const { return (_value);}
		};	
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs);
