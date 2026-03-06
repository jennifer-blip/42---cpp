/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:18:52 by jodde             #+#    #+#             */
/*   Updated: 2026/03/03 16:39:02 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
  private:
    Fixed const x;
    Fixed const y;

  public:
    // Constructors and destructors:
    Point();
    Point(float const X, float const Y);
    Point(Point const &rhs);
    ~Point();
    // Assignment operator
    Point &operator=(Point const &rhs);
    // Accessors
    Fixed const &getX() const;
    Fixed const &getY() const;
};
