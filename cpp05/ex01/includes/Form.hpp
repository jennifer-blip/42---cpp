/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:50:46 by jodde             #+#    #+#             */
/*   Updated: 2026/05/11 20:54:25 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "../includes/Bureaucrat.hpp"


class Bureaucrat;

class Form 
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	
	public:
		//constructors and destructors
		Form(std::string Name, int SignGrade, int ExecGrade);
		Form(const Form& src);
		~Form();
		//assignment operator
		Form& operator=(const Form& src);
		//accessors
		std::string getName() const;
		bool		getSigned() const;
		void		setSigned(bool status);
		int			getSignGrade() const;
		int			getExecGrade() const;
		//member functions
		int beSigned(Bureaucrat& bureaucrat);
		//Exceptions
		class GradeTooHighException : public std::exception
		{
			private:
				int	_value;
			
			public:
				GradeTooHighException(int Value) : _value(Value){}
				virtual const char *what() const throw () {return("Grade too high!");}
				int getValue (void) const { return (_value);}
		};
		class GradeTooLowException : public std::exception
		{
			private:
				int	_value;
			
			public:
				GradeTooLowException(int Value) : _value(Value){}
				virtual const char *what() const throw () {return("Grade too low!");}
				int getValue (void) const { return (_value);}
		};
};

std::ostream &operator<<(std::ostream &os, Form const &rhs);
