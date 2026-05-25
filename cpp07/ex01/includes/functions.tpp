/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:53:10 by jodde             #+#    #+#             */
/*   Updated: 2026/05/25 13:10:19 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iomanip>
#include <string>
#include "../includes/display.hpp"

template <typename T>
void displayArray(T& x, bool arrayEnd)
{
    std::cout << x << ' ';
    if (arrayEnd)
        std::cout << std::endl;
}

template <>
void displayArray(float& x, bool arrayEnd)
{
    std::cout << std::fixed << std::setprecision(1) << x << ' ';
    if (arrayEnd)
        std::cout << std::endl;
}

template <typename T>
void increment(T& x, bool arrayEnd)
{
    ++x;
    displayArray(x, arrayEnd);
}

template <typename T>
void increment(T const& x, bool arrayEnd)
{
    displayArray(x, arrayEnd);
    if (arrayEnd)
        display ("Cannot increment a const value", RED);
}

template <>
void increment(std::string& x, bool arrayEnd)
{
    x = x + "_append";
    displayArray(x, arrayEnd);
}

