/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntValue.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:31:52 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 19:36:42 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include "../includes/Scalar.hpp"
#include "../includes/display.hpp"

class	Scalar;

class	IntValue : public Scalar{
	private:
		int	_value;
	public:
		//canonical form
		IntValue(const std::string& input);
		IntValue(IntValue const& src);
		~IntValue();
		IntValue&	operator=(IntValue const& src);
		//member functions
		void	displayAsChar() const;
		void	displayAsInt() const;
		void	displayAsFloat() const;
		void	displayAsDouble() const;
};