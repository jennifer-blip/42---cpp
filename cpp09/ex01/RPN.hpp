/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:15:36 by jodde             #+#    #+#             */
/*   Updated: 2026/06/12 22:25:56 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class	RPN
{
	private:
		std::string	_arg;
		RPN();

	public:
		//constructors and destructors
		RPN(std::string const& arg);
		RPN(RPN const& src);
		~RPN();
		//assignment operator
		RPN&	operator=(RPN const& src);
		//accessors
		const std::string&	getArg() const;
		//member functions
		int		calculate() const;
};

void	logError(std::string message);
