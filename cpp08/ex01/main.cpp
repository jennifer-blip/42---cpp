/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/30 13:00:53 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include "Span.hpp"


static void fillRandom(std::vector<int>& vec, size_t N)
{
    for(size_t i = 0; i < N; i++)
        vec.push_back(static_cast<int>(random()));
}

int main(void)
{
    display("///////SPAN MANDATORY TEST", BROWN);
    {
        Span sp = Span(5);
        try { sp.addNumber(6); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { sp.addNumber(3); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { sp.addNumber(17); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { sp.addNumber(9); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { sp.addNumber(11); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { sp.addNumber(99); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        sp.displaySpan();
        try {
            std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
            std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    display("///////20 000 NUMBERS SPAN TEST", BROWN);
    {
        unsigned int        N = 20000;
        Span                sp = Span(N);
        std::vector<int>    vec;
        sp.addNumber(5);
        fillRandom(vec, N);
        try {sp.addNumber(vec.begin(), vec.end());} catch (std::exception& e) {std::cerr << e.what() <<std::endl;}
        try {
            std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
            std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        //sp.displaySpan();
    }
    return 0;
}
