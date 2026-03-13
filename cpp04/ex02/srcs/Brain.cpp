/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:13:20 by jodde             #+#    #+#             */
/*   Updated: 2026/03/13 08:54:23 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>
#include <sstream>

//Constructors and destructors
Brain::Brain()
{
	display("Brain default constructor called", BROWN);
}
Brain::Brain(std::string type)
{
	if (type == "Cat")
		setIdeas(type);
	if (type == "Dog")
		setIdeas(type);
	display(type + "Brain constructor called", BROWN);
} 
Brain::Brain(Brain const& src)
{
	display("Brain copy constructor called", BROWN);
	*this = src;
}

Brain::~Brain()
{
	display("Brain destructor called", BROWN);
}
//Assignment operator
Brain& Brain::operator=(Brain const& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

//Accessors
std::string* Brain::getIdeas(void)
{
	return (_ideas);
}

void	Brain::setIdeas(std::string type)
{
	if (type == "Cat")
	{
		for (int i = 0; i < 100; i++)
		{
			std::ostringstream oss;
			oss << i;
			_ideas[i] = "Cat idea nb " + oss.str() + "is dreaming of feather toys and fish";
		}
	}
	if (type == "Dog")
	{
		for (int i = 0; i < 100; i++)
		{
			std::ostringstream oss;
			oss << i;
			_ideas[i] = "Dog idea nb " + oss.str() + "is dreaming of bones and wooden sticks";
		}
	}
}
