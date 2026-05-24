/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:33:36 by jodde             #+#    #+#             */
/*   Updated: 2026/05/23 21:00:59 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/identify.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/display.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base    *generate(void)
{
    int random = std::rand () % 3;
    if (random == 0)
        return (new A);
    if (random == 1)
        return (new B);
    return (new C);
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        display("A class", BLUE); 
    if (dynamic_cast<B *>(p))
        display("B class", BLUE);
    if (dynamic_cast<C *>(p))
        display("C class", BLUE);
}

void    identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        return (display("A class", BLUE));
    }
    catch (std::exception &) {};
    try {
        (void)dynamic_cast<B&>(p);
        return (display("B class", BLUE));
    }
    catch (std::exception &) {};
    try {
        (void)dynamic_cast<C&>(p);
        return (display("C class", BLUE));
    }
    catch (std::exception &) {};
}
