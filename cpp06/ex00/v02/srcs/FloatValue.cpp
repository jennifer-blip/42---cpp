/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatValue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:33:06 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 21:00:17 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FloatValue.hpp"

FloatValue::FloatValue(const std::string& input){
	std::istringstream iss(input);
	iss >> _value;
}
		
FloatValue::FloatValue(FloatValue const& src) : Scalar(src)
{
	_value = src._value;
}

FloatValue::~FloatValue() {}

FloatValue&	FloatValue::operator=(FloatValue const& src){
	this->_value = src._value;
	return (*this);
}

//member functions
void	FloatValue::displayAsChar() const
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
void	FloatValue::displayAsInt() const
{
	displayInt(static_cast<int>(_value));
}
void	FloatValue::displayAsFloat() const
{
	displayFloat(_value);
}
void	FloatValue::displayAsDouble() const
{
	displayDouble(static_cast<double>(_value));
}
