/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:30 by jodde             #+#    #+#             */
/*   Updated: 2026/03/04 15:27:18 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"
#include <sstream>
#include <string>

// 42 subject tests
// int main(void)
// {
//     Fixed a;
//     Fixed const b(10);
//     Fixed const c(42.42f);
//     Fixed const d(b);
//     a = Fixed(1234.4321f);
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;
//     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//     std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//     return 0;
// }
// my own test
int main(void)
{
    std::string input;
    int Iinput;
    float Finput;
    Fixed a;

    std::cout << "enter arg or exit" << std::endl;
    while (true)
    {
        if (!std::getline(std::cin, input))
        {
            std::cout << "eof detected, program exits" << std::endl;
            return (0);
        }
        if (input == "exit")
            return (0);
        std::istringstream iss(input);
        if (iss >> Iinput && iss.eof())
        {
            a = Fixed(Iinput);
            std::cout << "a is " << a << std::endl;
            break;
        }
        else
        {
            iss.clear();
            iss.str(input);
            if (iss >> Finput && iss.eof())
            {
                a = Fixed(Finput);
                std::cout << "a is " << a << std::endl;
                break;
            }
            else
            {
                std::cout << "invalid input, please enter a float or a int" << std::endl;
                continue;
            }
        }
    }
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "a is " << a.toFloat() << " as float" << std::endl;
    return (0);
}
