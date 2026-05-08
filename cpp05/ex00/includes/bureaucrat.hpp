/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:41 by jodde             #+#    #+#             */
/*   Updated: 2026/05/08 20:43:25 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#define GREEN "\033[32m"
#define BROWN "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		//conctructors and destructors
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		~Bureaucrat();
		//assignment operator
		Bureaucrat operator= (Bureaucrat const& src);
		//accessors
		int			getGrade();
		std::string	getName();
};

class	WrongValueException : public Exception
{
	private : 
		int	_value;
	
	public: 
		WrongValueException(int grade) : _value(grade){}
		const char	*what() const {
			return "acceptable grade range is [1-150]";
		}
		int	getValue() const {
			return _value;
		}
};

		