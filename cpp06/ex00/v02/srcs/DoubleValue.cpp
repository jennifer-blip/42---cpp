/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleValue.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:33:06 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 21:00:44 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DoubleValue.hpp"

DoubleValue::DoubleValue(const std::string& input){
	std::istringstream iss(input);
	iss >> _value;
}
		
DoubleValue::DoubleValue(DoubleValue const& src) : Scalar(src)
{
	_value = src._value;
}

DoubleValue::~DoubleValue() {}

DoubleValue&	DoubleValue::operator=(DoubleValue const& src){
	this->_value = src._value;
	return (*this);
}

//member functions
void	DoubleValue::displayAsChar() const
{
	if (static_cast<int>(_value) > 31 && static_cast<int>(_value) < 128)
	{
		displayChar(static_cast<char>(_value));
		return;
	}
	if (static_cast<int>(_value) > 0 && static_cast<int>(_value) < 32)
	{
		display("char : Non displayable", NONE);
		return;
	}
	else
		display("char : Impossible", NONE);
	return;
}
void	DoubleValue::displayAsInt() const
{
	displayInt(static_cast<int>(_value));
}
void	DoubleValue::displayAsFloat() const
{
	displayFloat(static_cast<float>(_value));
}
void	DoubleValue::displayAsDouble() const
{
	displayDouble(_value);
}
