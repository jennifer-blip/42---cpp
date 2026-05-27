/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:33:36 by jodde             #+#    #+#             */
/*   Updated: 2026/05/27 21:00:59 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <stdexcept>

class   Span
{
    private :
        unsigned int        _max;
        std::vector<int>    _vec;
        Span();
    
    public:
        //constructors and destructors
        Span(unsigned int N);
        Span(Span const & src);
        ~Span();
        //assignment operator
        Span& operator=(Span const & rhs);
        //accessors
        unsigned int    getMax(void) const;
        //member functions
        void    addNumber(int number);
        void    addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan(void) const;
        int     longestSpan(void) const;
        void    displaySpan(void) const;
};
