/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:04:54 by jodde             #+#    #+#             */
/*   Updated: 2026/03/17 16:24:36 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
Cure::Cure() : AMateria("cure")
{
	display(getType() + " default constructor called", GREY);
}
Cure::Cure(std::string const& type) : AMateria (type)
{
	display(getType() + " constructor called", GREY);
}
Cure::Cure(Cure const& src) : AMateria("cure_cpy")
{
	*this = src;
	display(getType() + " copy constructor called", GREY);
}
Cure::~Cure()
{
	display(getType() + " destructor called", GREY);
}
//assignment operator
Cure&	Cure::operator=(Cure const& src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
		display(getType() + " assignement operator called", GREY);
	}
	return (*this);
}
//Member functions
Cure*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	display("* heals " + target.getName() + " 's wounds *", YELLOW);
}
