/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:58:24 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 12:07:39 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class	WrongAnimal
{
	protected :
		std::string	_type;
	public	:
	//Constructors and destructors
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const& src);
		~WrongAnimal();
	//Assignment operator
		WrongAnimal& operator=(WrongAnimal const& srcs);
	//accessors
		std::string 	getType(void) const;
		void			setType(std::string type);
	//member functions
		void	makeSound() const;
};

