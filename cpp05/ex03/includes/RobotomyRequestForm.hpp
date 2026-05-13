/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:22:13 by jodde             #+#    #+#             */
/*   Updated: 2026/05/12 17:23:05 by jodde            ###   ########.fr       */
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

class  RobotomyRequestForm : public AForm
{
	private :
		std::string _target;
		
	public:
		//constructors and destructors
		RobotomyRequestForm(std::string Target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm();
		//assignment operator
		RobotomyRequestForm& operator=(RobotomyRequestForm const & src);
		//accessors
		std::string getTarget() const;
		//member functions
		void	execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &rhs);