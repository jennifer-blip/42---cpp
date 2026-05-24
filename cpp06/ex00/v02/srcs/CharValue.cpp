/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharValue.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:33:06 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 20:50:31 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CharValue.hpp"

CharValue::CharValue(const std::string& input){
	std::istringstream iss(input);
	iss >> _value;
}
		
CharValue::CharValue(CharValue const& src) : Scalar(src)
{
	_value = src._value;
}

CharValue::~CharValue() {}

CharValue&	CharValue::operator=(CharValue const& src){
	this->_value = src._value;
	return (*this);
}

//member functions
void	CharValue::displayAsChar() const
{
	displayChar(_value);
}
void	CharValue::displayAsInt() const
{
	displayInt(static_cast<int>(_value));
}
void	CharValue::displayAsFloat() const
{
	displayFloat(static_cast<float>(_value));
}
void	CharValue::displayAsDouble() const
{
	displayDouble(static_cast<double>(_value));
}
