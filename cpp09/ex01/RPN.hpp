/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:15:36 by jodde             #+#    #+#             */
/*   Updated: 2026/06/12 22:25:56 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <stdexcept>

struct Token
{
	bool 	isOperator;
	int		nb;
	char	op;
};

class	RPN
{
	private:
		std::stack<Token>	_stk;	
		std::string			_arg;
		RPN();
	
	public:
		//constructors and destructors
		RPN(std::string arg);
		RPN(RPN const& src);
		~RPN();
		//assignment operator
		RPN&	operator=(RPN const& src);
		//accessors
		const std::stack<Token>&	getStack() const;
		const std::string&		getArg() const;
		//member functions
		void	checkArg();
		bool	isValidOperator(char c);
		void	fillStack();
		void	calculate();
		void	displayStack();
};

void	logError(std::string message);