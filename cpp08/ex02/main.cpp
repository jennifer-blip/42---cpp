/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:43:13 by jodde             #+#    #+#             */
/*   Updated: 2026/05/30 12:52:32 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <vector>
#include <stack>
#include "MutantStack.hpp"

enum color
{
	RESET,
	RED,
	BROWN,
	GREEN,
	BLUE
};

void	display(std::string msg, color col)
{
	switch (col)
	{
		case (RED):
		{
			std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BROWN):
		{
			std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (GREEN):
		{
			std::cout << "\033[32m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BLUE):
		{
			std::cout << "\033[34m" << msg << "\033[0m" << std::endl;
			break;
		}		
		default :
			std::cout << msg << std::endl;
	}
}

int main()
{
	display("/////////MANDATORY TEST", BROWN);
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0; 
}