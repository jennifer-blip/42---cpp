/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:43:13 by jodde             #+#    #+#             */
/*   Updated: 2026/05/30 17:55:55 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <list>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include "MutantStack.hpp"

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

template <typename T>
void	displayMutant(MutantStack<T>& mutant)
{
	typename MutantStack<T>::iterator it = mutant.begin();
	typename MutantStack<T>::iterator ite = mutant.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
void	displayStack(std::stack<T>& s)
{
	std::cout << "stack size is " << s.size() << std::endl;
	display ("stack content is : ", RED);
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
	std::cout << "now stack size is " << s.size() << std::endl;
}

int main()
{
	{
		display("/////////MANDATORY TEST", BROWN);
		display("MutantStack<int> creation", GREEN);
		MutantStack<int> mstack;
		display("push 2 elements : 5 then 17 in the MutantStack", BROWN);
		mstack.push(5);
		mstack.push(17);
		std::cout << "size of the stack " << mstack.size() << std::endl;
		display("display top element", GREEN);
		std::cout << mstack.top() << std::endl;
		display("remove top element", GREEN);
		mstack.pop();
		std::cout << "size of the stack " << mstack.size() << std::endl;
		display("display all remaining elements of the stack", GREEN);
		displayMutant(mstack);
		display("push 3 new elements", BROWN);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		display("display all remaining elements of the stack - MY FUNCTION", GREEN);
		displayMutant(mstack);
		display("display all remaining elements of the stack - MANDATORY TEST", GREEN);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		display("create a stack copy of the mutant stack", GREEN);
		std::stack<int> s(mstack);
		display("display all elements of the stack copy - MY FUNCTION", GREEN);
		displayStack(s);
	}
	{
		display("/////////MY OWN TESTS", BROWN);
		std::vector<int> v;
		srand(time(NULL));
		for (int i=0; i < 500; i++)
		{
			int value = rand ();
			v.push_back(value);
		}
		MutantStack<int> mstack(v);
		displayMutant(v);
	} 
	return 0; 
}