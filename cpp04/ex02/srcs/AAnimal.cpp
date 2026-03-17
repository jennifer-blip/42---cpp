/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:59:25 by jodde             #+#    #+#             */
/*   Updated: 2026/03/17 15:54:42 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
AAnimal::AAnimal() : _type("Default AAnimal")
{
	display("AAnimal default constructor called", BROWN);
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	display("AAnimal constructor called with type " + getType(), BROWN);
}
AAnimal::AAnimal(AAnimal const& src) : _type(src._type)
{
	display(getType() + "AAnimal copy constructor called", BROWN);
}
AAnimal::~AAnimal()
{
	display("Animal destructor called", BROWN);
}
//Assignment operator
AAnimal& AAnimal::operator=(AAnimal const& src)
{
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

//accessors
std::string AAnimal::getType(void) const
{
	return(_type);
}
void	AAnimal::setType(std::string type)
{
	_type = type;
}
//member functions
void	AAnimal::makeSound() const
{
	display (getType() + " is singing a beautiful lovesong", GREEN);
}

