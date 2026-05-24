/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 14:47:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/identify.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>



int main()
{
    for (int i = 0; i < 7; i++)
    {
        std::ostringstream oss;
        oss << i;
        display("///////RANDOMLY GENERATED CLASS TEST NB " + oss.str() , BROWN);
        Base *base = generate();
        display("Base * test", RESET);
        identify(base);
        display("Base& test", RESET);
        identify(base);
        delete base;
    }
    return (0);
}
