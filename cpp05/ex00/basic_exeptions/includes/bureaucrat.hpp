/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:45:41 by jodde             #+#    #+#             */
/*   Updated: 2026/05/11 15:39:20 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <exception>

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
		Bureaucrat& operator= (Bureaucrat const& src);
		//accessors
		int			getGrade(void) const;
		std::string	getName(void) const;
		//member functions to code
		//increment
		//decreent
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs);
