/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:44:36 by jodde             #+#    #+#             */
/*   Updated: 2026/05/29 21:05:59 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const & src);
		~MutantStack();
		MutantStack& operator=(MutantStack const& src);
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack
}