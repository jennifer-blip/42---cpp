/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:22:13 by jodde             #+#    #+#             */
/*   Updated: 2026/05/12 17:23:01 by jodde            ###   ########.fr       */
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

class  PresidentialPardonForm : public AForm
{
	private :
		std::string	_target;
		
	public:
		//constructors and destructors
		PresidentialPardonForm(std::string Target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm();
		//assignment operator
		PresidentialPardonForm& operator=(PresidentialPardonForm const & src);
		//accessors
		std::string getTarget() const;
		//member functions
		void	execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &rhs);