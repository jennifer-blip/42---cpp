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


void	logError(std::string message)
{
	std::string msg = "ERROR -" + message;
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

//constructors and destructors
RPN::RPN(){}
RPN::RPN(std::string arg) : _arg(arg){}
RPN::RPN(RPN const& src){ *this = src;}
RPN::~RPN(){}

//assignment operator
RPN&	RPN::operator=(RPN const& src)
{
	_stk = src.getStack();
	_arg = src.getArg();
	return (*this);
}

//accessors
const std::stack<Token>&	RPN::getStack() const { return (_stk);}
const std::string&		RPN::getArg()  const {return (_arg);}

//member functions

bool		RPN::isValidOperator(char c)
{
	if (c != '/' && c != '*' && c != '-' && c != '+')
		return (false);
	return (true);
}
void	RPN::checkArg()
{
	int	counter = 0;
	for (std::string::iterator it = _arg.begin(); it != _arg.end(); ++it)
	{
		if (*it == ' ')
			continue;
		if (it == _arg.begin())
		{
			if (!isdigit(*it))
			{
				std::cout << *it << " : ";
				throw (std::logic_error("arg: nb wrong format"));
			}
			counter++;
			continue;
		}
		if (counter % 2 == 0)
		{
			if(!RPN::isValidOperator(*it))
			{
				std::cout << *it << " : ";
				throw (std::logic_error("arg: operator wrong format"));
			}
		}
		if (counter % 2 != 0)
		{
			if (!(isdigit(*it)))
			{
				std::cout << *it << " : ";
				throw (std::logic_error("arg: nb wrong format"));
			}
		}
		counter++;
	}
}
void	RPN::fillStack()
{
	for (std::string::reverse_iterator it = _arg.rbegin(); it != _arg.rend(); ++it)
	{
		Token	tok;
		if (isdigit(*it))
		{
			tok.isOperator = false;
			std::istringstream is(std::string(1, *it));
			is >> tok.nb;
			tok.op = 0;	
		}
		else if (*it == '/' || *it == '*' || *it == '-' || *it == '+')
		{
			tok.isOperator = true;
			tok.nb = -1;
			tok.op = *it;
		}
		else if (*it == ' ')
			continue;
		else if (*it != ' ')
		{
			std::cout << *it << " ";
			throw (std::logic_error("arg : unappropriate argument"));
		}
		_stk.push(tok);
	}
}

void	RPN::displayStack()
{
	while (!this->getStack().empty())
	{
		Token	tok = this->_stk.top();
		if (tok.isOperator)
			std::cout << tok.op << std::endl;
		else
			std::cout << tok.nb << std::endl;
		this->_stk.pop();
	}
}

static void	calcResult(int& result, int tmp, char c)
{
	int i;
	char op[4] = {'/' , '*' , '-' , '+'};
	for (i = 0; i < 4; i++)
	{
		if (c == op[i])
			break;
	}
	switch (i)
	{
		case (0):
		{
			if (tmp == 0)
				throw (std::logic_error("logic error : division by zero"));
			result = result / tmp;
			break;
		}
		case (1):
		{
			result = result * tmp;
			break;
		}
		case (2):
		{
			result = result - tmp;
			break;
		}
		case (3):
		{
			result = result + tmp;
			break;
		}
	}
	
}
void	RPN::calculate()
{
	Token	tok = this->_stk.top();
	int 	result = static_cast<int>(tok.nb);
	int		tmp[2];
	char	tmpOp;
	bool	opStatus = false;
	bool	tmpStatus[2] = {false, false};
	this->_stk.pop();
	while (!this->getStack().empty())
	{
		tok = this->_stk.top();
		if (tok.isOperator && !tmpStatus[1])
		{
			try {calcResult(result, tmp[0], tok.op);} catch(std::exception& e) {std::cerr << e.what() << std::endl;}
			tmpStatus[0] = false;
		}
		if (tok.isOperator && tmpStatus[1])
		{
			if(!opStatus)
			{
				tmpOp = tok.op;
				opStatus = true;
			}
			else if (opStatus)
			{
				try {calcResult(tmp[0], tmp[1], tmpOp);} catch(std::exception& e) {std::cerr << e.what() << std::endl;}
				try {calcResult(result, tmp[0], tok.op);} catch(std::exception& e) {std::cerr << e.what() << std::endl;}
				tmpStatus[1] = false;
				opStatus = false;
			}
		}
		if (!tok.isOperator && !tmpStatus[0])
		{
			tmp[0] = static_cast<int>(tok.nb);
			tmpStatus[0] = true;
		}
		else if (!tok.isOperator && tmpStatus[0])
		{
			tmp[1] = static_cast<int>(tok.nb);
			tmpStatus[1] = true;
		}
		this->_stk.pop();
	}
	std::cout << result << std::endl;	
}