/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:19:42 by jodde             #+#    #+#             */
/*   Updated: 2026/03/03 16:51:34 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	area(Point A, Point B, Point P)
{
	return (((A.getX() - P.getX()) * (B.getY() - P.getY())) - ((A.getY() - P.getY()) * (B.getX() - P.getX())));
}

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
	Fixed ab = area(a, b, p);
	Fixed ac = area(a, c, p);
	Fixed bc = area(b, c, p);
	if ((ab > 0 && ac > 0 && bc > 0) ||
        (ab < 0 && ac < 0 && bc < 0))
        return true;
	return (false);
}
