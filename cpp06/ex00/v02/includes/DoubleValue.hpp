/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleValue.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:31:52 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 19:36:33 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include "../includes/Scalar.hpp"
#include "../includes/display.hpp"

class	Scalar;

class	DoubleValue : public Scalar{
	private:
		double	_value;
	public:
		//canonical form
		DoubleValue(const std::string& input);
		DoubleValue(DoubleValue const& src);
		~DoubleValue();
		DoubleValue&	operator=(DoubleValue const& src);
		//member functions
		void	displayAsChar() const;
		void	displayAsInt() const;
		void	displayAsFloat() const;
		void	displayAsDouble() const;
};
