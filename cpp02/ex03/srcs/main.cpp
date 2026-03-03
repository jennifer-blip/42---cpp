/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:30 by jodde             #+#    #+#             */
/*   Updated: 2026/03/03 16:34:29 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"
#include <sstream>

int main(int argc, char **argv) 
{
    if (argc != 7)
    {
        std::cout << "Usage: " << argv[0]
                  << " <Ax> <Ay> <Bx> <By> <Cx> <Cy>" << std::endl;
        return 1;
    }
    float coord[6];
    for (int i = 1; i < argc; i++)
    {
        std::istringstream iss(argv[i]);
        iss >> coord[i - 1];

        if (iss.fail() || !iss.eof())
        {
            std::cout << "Invalid coordinate: " << argv[i] << std::endl;
            return 1;
        }
    }
    Point A(coord[0], coord[1]);
    Point B(coord[2], coord[3]);
    Point C(coord[4], coord[5]);
    while (true)
    {
        std::string input;
        std::cout << "Enter a point (x y) or 'exit' to quit: ";
        std::getline(std::cin, input);
        if (input == "exit")
            break;
        std::istringstream iss(input);
        float x, y;
        if (!(iss >> x >> y) || !iss.eof())
        {
            std::cout << "Invalid input. Please enter coordinates in the format 'x y'." << std::endl;
            continue;
        }
        Point P(x, y);
        if (bsp(A, B, C, P))
            std::cout << "Point is inside the triangle." << std::endl;
        else
            std::cout << "Point is outside the triangle." << std::endl;
    }
    return 0;
}
