/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:44:36 by jodde             #+#    #+#             */
/*   Updated: 2026/05/30 12:51:43 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	
		MutantStack() : std::stack<T>() {};
		MutantStack(MutantStack const & src): std::stack<T>(src) {};
		~MutantStack(){};
		MutantStack& operator=(MutantStack const& src) {std::stack<T>::operator=(src); return(*this);};
		
		typedef typename std::stack<T>::container_type::iterator 				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		
		iterator begin() {return (this->c.begin());}
		iterator end()	{return (this->c.end());}
		const_iterator	begin() const	{return(this->c.begin());}
		const_iterator	end() const	{return(this->c.end());}
		reverse_iterator rbegin()	{return(this->c.rbegin());}
		reverse_iterator rend()	{return (this->c.rend());}
		const_reverse_iterator rbegin() const {return (this->c.rbegin());}
		const_reverse_iterator rend() const {return (this->c.rend());}		
};