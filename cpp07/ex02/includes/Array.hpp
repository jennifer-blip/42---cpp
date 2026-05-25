/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/25 14:47:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "../includes/display.hpp"
#include "../includes/Array.tpp"

template <typename T>
class   Array
{
    private:
        unsigned int    _size;
        T               *_data;
    public:
        //constructors and destructors
        Array();
        Array(unsigned int n);
        Array(Array const& src);
        ~Array();
        //assignment operator
        Array<T>& operator=(Array const& src);
        //member function
        unsigned int size(void) const;
        T& getData(unsigned int idx) const;
        T& operator[](unsigned int idx) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Array<T> const& src);
