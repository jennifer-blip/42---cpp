/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharValue.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:31:52 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 18:39:12 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include "../includes/Scalar.hpp"
#include "../includes/display.hpp"

class	Scalar;

class	CharValue : public Scalar{
	private:
		char	_value;
	public:
		//canonical form
		CharValue(const std::string& input);
		CharValue(CharValue const& src);
		~CharValue();
		CharValue&	operator=(CharValue const& src);
		//member functions
		void	displayAsChar() const;
		void	displayAsInt() const;
		void	displayAsFloat() const;
		void	displayAsDouble() const;
};