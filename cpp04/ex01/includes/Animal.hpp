/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:58:24 by jodde             #+#    #+#             */
/*   Updated: 2026/03/13 09:05:36 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class	Animal
{
	protected :
		std::string	_type;
	public	:
	//Constructors and destructors
		Animal();
		Animal(std::string type);
		Animal(Animal const& src);
		virtual ~Animal();
	//Assignment operator
		Animal& operator=(Animal const& srcs);
	//accessors
		std::string 	getType(void) const;
		void			setType(std::string type);
	//member functions
		virtual void	makeSound() const;
};

