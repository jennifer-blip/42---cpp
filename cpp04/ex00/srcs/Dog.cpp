/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:00:58 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 11:57:07 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
Dog::Dog() : Animal("Dog")
{
	display("Dog default constructor called", BROWN);
}
Dog::Dog(std::string Name) : Animal("Dog"), _name (Name)
{
	display("Dog constructor called", BROWN);
}

Dog::Dog(Dog const& src) : Animal(src._type)
{
	display(getType() + " copy constructor called", BROWN);
}
Dog::~Dog()
{
	display("Dog destructor called", BROWN);
}
//Assignment operator
Dog& Dog::operator=(Dog const& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		_name = src.getName();
	}
	return (*this);
}

//accessors
std::string Dog::getName(void) const
{
	return(_name);
}

void	Dog::setName(std::string Name)
{
	_name = Name;
}
//member functions
void	Dog::makeSound() const
{
	display(getType() + "/// A cheerful bark greets the morning light.", GREEN);
}
