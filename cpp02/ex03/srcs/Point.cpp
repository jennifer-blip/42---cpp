/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:19:08 by jodde             #+#    #+#             */
/*   Updated: 2026/03/03 16:39:31 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//constructors and destructors
Point::Point(): x(0), y(0){}
Point::Point(float const X, float const Y): x(X), y(Y){}
Point::Point(Point const& rhs) : x(rhs.x), y(rhs.y) {}
Point::~Point(){}

//Assignment operator
Point&	Point::operator=(Point const& rhs)
{
	(void)rhs;
	return (*this);
}
//Accessors
Fixed const&	Point::getX() const
{
	return (this->x);
}
Fixed const&	Point::getY() const
{
	return (this->y);
}
