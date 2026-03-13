/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:00:19 by jodde             #+#    #+#             */
/*   Updated: 2026/03/13 09:06:50 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

//Constructors and destructors
Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain(this->_type);
	display("Cat default constructor called", BROWN);
}
Cat::Cat(std::string Name) : Animal("Cat"), _name (Name)
{
	this->_brain = new Brain(this->_type);
	display("Cat constructor called", BROWN);
}

Cat::Cat(Cat const& src)
{
	this->_brain = NULL;
	*this = src;
	display(getType() + " copy constructor called", BROWN);
}
Cat::~Cat()
{
	delete this->_brain;
	display("Cat destructor called", BROWN);
}
//Assignment operator
Cat& Cat::operator=(Cat const& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
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

void	Cat::displayIdeas() const
{
	for (int i = 0; i < 100; i++)
		display(_brain->getIdeas()[i], GREEN);
}
