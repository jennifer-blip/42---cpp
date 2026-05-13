/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:50:46 by jodde             #+#    #+#             */
/*   Updated: 2026/05/13 13:06:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "../includes/Bureaucrat.hpp"


class Bureaucrat;

class AForm 
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	
	public:
		//constructors and destructors
		AForm();
		AForm(std::string Name, int SignGrade, int ExecGrade);
		AForm(const AForm& src);
		virtual ~AForm();
		//assignment operator
		AForm& operator=(const AForm& src);
		//accessors
		std::string getName() const;
		bool		getIsSigned() const;
		void		setSigned(bool status);
		int			getSignGrade() const;
		int			getExecGrade() const;
		//member functions
		int beSigned(Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const &executor)const = 0;
		//Exceptions
		class GradeTooHighException : public std::exception
		{
			private:
				int	_value;
			
			public:
				GradeTooHighException(int Value) : _value(Value){}
				virtual ~GradeTooHighException() throw() {}
				virtual const char *what() const throw () {return("Grade too high!");}
				int getValue (void) const { return (_value);}
		};
		class GradeTooLowException : public std::exception
		{
			private:
				int	_value;
			
			public:
				GradeTooLowException(int Value) : _value(Value){}
				virtual ~GradeTooLowException() throw(){}
				virtual const char *what() const throw () {return("Grade too low!");}
				int getValue (void) const { return (_value);}
		};
};

std::ostream &operator<<(std::ostream &os, AForm const &rhs);
