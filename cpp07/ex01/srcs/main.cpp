/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/25 14:47:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/display.hpp"
#include "../includes/functions.tpp"
#include "../includes/iter.tpp"

int main(void)
{
    {
        display("///////ITER TEST WITH INT", BROWN);
        size_t const    length = 5;
        int             intArray[length] = {10, 11, 12, 13, 14};
        display("display function", BLUE);
        iter<int>(intArray, length, &displayArray);
        display("increment function", BLUE);
        iter<int>(intArray, length, &increment);
    }
    {
        display("///////ITER TEST WITH CHAR", BROWN);
        size_t const    length = 10;
        char            charArray[length] = {'d', 'e', 'f', 'g', 'h', 'i' , 'j', 'k', 'l', 'm'};
        display("display function", BLUE);
        iter<char>(charArray, length, &displayArray);
        display("increment function", BLUE);
        iter<char>(charArray, length, &increment);
    }
    {
        display("///////ITER TEST WITH FLOAT", BROWN);
        size_t const    length = 4;
        float            floatArray[length] = {101, 102, 103, 104.5};
        display("display function", BLUE);
        iter<float>(floatArray, length, &displayArray);
        display("increment function", BLUE);
        iter<float>(floatArray, length, &increment);
    }
    {
        display("///////ITER TEST WITH STRING", BROWN);
        size_t const    length = 2;
        std::string            stringArray[length] = {"hello", "world"};
        display("display function", BLUE);
        iter<std::string>(stringArray, length, &displayArray);
        display("increment function", BLUE);
        iter<std::string>(stringArray, length, &increment);
    }
    {
        display("///////ITER TEST WITH CONSTSTRING", BROWN);
        size_t const    length = 2;
        std::string const           stringArray[length] = {"hello", "world"};
        display("display function", BLUE);
        iter<std::string const>(stringArray, length, &displayArray);
        display("increment function", BLUE);
        iter<std::string const>(stringArray, length, &increment);
    }
    return 0;
}
