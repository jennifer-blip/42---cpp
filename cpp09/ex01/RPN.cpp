/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:25:56 by jodde             #+#    #+#             */
/*   Updated: 2026/06/13 12:44:35 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"
#include <stack>

void	logError(std::string message)
{
	std::string msg = "ERROR -" + message;
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

//constructors and destructors
RPN::RPN(){}
RPN::RPN(std::string const& arg) : _arg(arg){}
RPN::RPN(RPN const& src){ *this = src;}
RPN::~RPN(){}

//assignment operator
RPN&	RPN::operator=(RPN const& src)
{
	_arg = src.getArg();
	return (*this);
}

//accessors
const std::string&	RPN::getArg() const {return (_arg);}

//member functions
static int	applyOperator(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw (std::logic_error("division by zero"));
			return (a / b);
	}
	throw (std::logic_error("unknown operator"));
}

int	RPN::calculate() const
{
	std::stack<int>	operands;

	for (std::string::const_iterator it = _arg.begin(); it != _arg.end(); ++it)
	{
		if (*it == ' ')
			continue;
		if (isdigit(*it))
			operands.push(*it - '0');
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (operands.size() < 2)
				throw (std::logic_error("arg: not enough operands"));
			int b = operands.top(); operands.pop();
			int a = operands.top(); operands.pop();
			operands.push(applyOperator(a, b, *it));
		}
		else
			throw (std::logic_error("arg: invalid character in expression"));
	}
	if (operands.size() != 1)
		throw (std::logic_error("arg: invalid expression"));
	return (operands.top());
}
