/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatValue.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:31:52 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 19:36:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include "../includes/Scalar.hpp"
#include "../includes/display.hpp"

class	Scalar;

class	FloatValue : public Scalar{
	private:
		float	_value;
	public:
		//canonical form
		FloatValue(const std::string& input);
		FloatValue(FloatValue const& src);
		~FloatValue();
		FloatValue&	operator=(FloatValue const& src);
		//member functions
		void	displayAsChar() const;
		void	displayAsInt() const;
		void	displayAsFloat() const;
		void	displayAsDouble() const;
};