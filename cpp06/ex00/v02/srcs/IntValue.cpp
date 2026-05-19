/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntValue.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:33:06 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 20:55:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IntValue.hpp"

IntValue::IntValue(const std::string& input){
	std::istringstream iss(input);
	iss >> _value;
}
		
IntValue::IntValue(IntValue const& src) : Scalar(src)
{
	_value = src._value;
}

IntValue::~IntValue() {}

IntValue&	IntValue::operator=(IntValue const& src){
	this->_value = src._value;
	return (*this);
}

//member functions
void	IntValue::displayAsChar() const
{
	if (_value > 31 && _value < 128)
	{
		displayChar(static_cast<char>(_value));
		return;
	}
	if (_value > 0 && _value < 32)
	{
		display("char : Non displayable", NONE);
		return;
	}
	else
		display("char : Impossible", NONE);
	return;
}
void	IntValue::displayAsInt() const
{
	displayInt(_value);
}
void	IntValue::displayAsFloat() const
{
	displayFloat(static_cast<float>(_value));
}
void	IntValue::displayAsDouble() const
{
	displayDouble(static_cast<double>(_value));
}