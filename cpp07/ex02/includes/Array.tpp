/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/25 14:47:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>
#include "../includes/Array.hpp"

template <typename T>
 Array<T>::Array(): _size(0)
 {
    this->_data = NULL; 
    display("default constructor called, array is empty", RED);
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n) 
{
    this->_data = new T[n]();
    display("array constructor called", BLUE);
}
       
template <typename T>
Array<T>::Array(Array const& src) 
{ 
    this->_size = src.size();
    this->_data = new T[src.size()]; 
    for (unsigned int i = 0; i < src.size(); i++)
                this->_data[i] = src._data[i];
}
       
template <typename T>
Array<T>::~Array()
{
    delete[] this->_data; 
    display("array destructor called", BLUE);
}
       

//assignment operator
template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& src)
{
    if (this->_data)
        delete[] this->_data;
    this->_size = src.size();
    this->_data = new T[src.size()]; 
    for (unsigned int i = 0; i < src.size(); i++)
        this->_data[i] = src._data[i];
    return (*this);
}

//member function
template <typename T>
unsigned int Array<T>::size(void) const 
{
    return (this->_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) const
{
    if (this->_size <= idx)
        throw std::out_of_range("unable to access, index is out of range" + std::to_string(idx));
    return(this->_data[idx]);
}

template <typename T>
T& Array<T>::getData(unsigned int idx) const
{
    if (this->_size <= idx)
        throw std::out_of_range("unable to access, index is out of range" + std::to_string(idx));
    return(this->_data[idx]);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Array<T> const& src)
{
    for (unsigned int i = 0; i < src.size() ; i++)
        os << src.getData(i) << ' ';
    os << std::endl;
    return (os);
}
