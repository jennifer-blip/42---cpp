/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:05:05 by jodde             #+#    #+#             */
/*   Updated: 2026/03/16 18:04:45 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>


//Constructors and destructors
Ice::Ice() : AMateria("ice")
{
	display(getType() + " default constructor called", GREY);
}
Ice::Ice(std::string const & type) : AMateria (type)
{
	display(getType() + " constructor called", GREY);
}
Ice::Ice(Ice const& src) : AMateria("ice_cpy")
{
	*this = src;
	display(getType() + " copy constructor called", GREY);
}
Ice::~Ice()
{
	display(getType() + " destructor called", GREY);
}
//assignment operator
Ice&	Ice::operator=(Ice const& src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
		display(getType() + " assignement operator called", GREY);
	}
	return (*this);
}
//Member functions
Ice*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	display("* shoots an ice bolt at " + target.getName() + " *", BLUE);
}
