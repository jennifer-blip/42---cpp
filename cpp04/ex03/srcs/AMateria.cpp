/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:49:34 by jodde             #+#    #+#             */
/*   Updated: 2026/03/16 18:25:04 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
AMateria::AMateria(std::string const & type) : _type(type)
{
	display(getType() + " AMateria constructor called", GREY);
}
AMateria::AMateria(AMateria const& src) : _type(src.getType())
{
	display(getType() + " AMateria copy constructor called", GREY);
}
AMateria::~AMateria()
{
	display(getType() + " AMateria destructor called", GREY);
}
//assignment operator
AMateria&	AMateria::operator=(AMateria const& src)
{
	if (this != &src)
	{
		this->_type = src.getType();
		display(getType() + " AMateria assignement operator called", GREY);
	}
	return (*this);
}
//Accessors
std::string const&	AMateria::getType() const
{
	return (this->_type);
}
//Member functions
void		AMateria::use(ICharacter& target)
{
	display(target.getName() + " is being attacked by undedined Materia", YELLOW);
}
