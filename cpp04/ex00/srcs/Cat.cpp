/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:00:19 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 11:56:30 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
Cat::Cat() : Animal("Cat")
{
	display("Cat default constructor called", BROWN);
}
Cat::Cat(std::string Name) : Animal("Cat"), _name (Name)
{
	display("Cat constructor called", BROWN);
}

Cat::Cat(Cat const& src) : Animal(src._type)
{
	display(getType() + " copy constructor called", BROWN);
}
Cat::~Cat()
{
	display("Cat destructor called", BROWN);
}
//Assignment operator
Cat& Cat::operator=(Cat const& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		_name = src.getName();
	}
	return (*this);
}

//accessors
std::string Cat::getName(void) const
{
	return(_name);
}

void	Cat::setName(std::string Name)
{
	_name = Name;
}
//member functions
void	Cat::makeSound() const
{
	display(getType() + "/// Tiny paws patter, mewing with delight.", GREEN);
}
