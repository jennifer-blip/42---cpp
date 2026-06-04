#pragma once
#include <stack> 
///use the stack container here because stack follows LIFO (we will face a inverted equation so we need to invert the numbers back)
#include <fstream>
#include <iostream>
#include <string>

class	RPN{
	public:
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();

		int	calculate(const std::string& expression);
};