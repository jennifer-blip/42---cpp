/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:59:25 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 11:56:06 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
Animal::Animal() : _type("Default Animal")
{
	display("Animal default constructor called", BROWN);
}

Animal::Animal(std::string type) : _type(type)
{
	display("Animal constructor called with type " + getType(), BROWN);
}
Animal::Animal(Animal const& src) : _type(src._type)
{
	display(getType() + "Animal copy constructor called", BROWN);
}
Animal::~Animal()
{
	display("Animal destructor called", BROWN);
}
//Assignment operator
Animal& Animal::operator=(Animal const& src)
{
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

//accessors
std::string Animal::getType(void) const
{
	return(_type);
}
void	Animal::setType(std::string type)
{
	_type = type;
}
//member functions
void	Animal::makeSound() const
{
	display (getType() + " is singing a beautiful lovesong", GREEN);
}

