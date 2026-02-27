/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:18:52 by jodde             #+#    #+#             */
/*   Updated: 2026/02/27 15:32:42 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const x;
		Fixed const y;
		
	public:
	//Constructors and destructors:
		Point(): x(0), y(0);
		Point(float const X, float const Y): x(X), y(Y);
		Point(Point const& rhs);
		~Point();
	//Assignment operator
		Point&	operator=(Point const& rhs);
	//Accessors
		Point&	getX() const;
		Point&	getY() const;
		void	setX(Fixed& const value);
		void	setY(Fixed& const value);
}