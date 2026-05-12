/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:22:13 by jodde             #+#    #+#             */
/*   Updated: 2026/05/12 17:23:12 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;
		
	public:
		//constructors and destructors
		ShrubberyCreationForm(std::string Target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm();
		//assignment operator
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & src);
		//accessors
		std::string getTarget() const;
		//member functions
		void	execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &rhs);