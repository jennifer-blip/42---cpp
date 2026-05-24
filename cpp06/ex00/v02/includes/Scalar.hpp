/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:27:53 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 19:29:26 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "../includes/display.hpp"

class Scalar {
	public:
		//canonical form
		Scalar();
		Scalar(Scalar const& src);
		virtual ~Scalar();
		Scalar& operator=(Scalar const& src);
		//methods
		virtual void	displayAsChar() const = 0;
		virtual void	displayAsInt() const = 0;
		virtual void	displayAsFloat() const = 0;
		virtual void	displayAsDouble() const = 0;
};

