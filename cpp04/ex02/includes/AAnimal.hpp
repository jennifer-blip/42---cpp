/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:58:24 by jodde             #+#    #+#             */
/*   Updated: 2026/03/13 09:15:26 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class	AAnimal
{
	protected :
		std::string	_type;
	public	:
	//Constructors and destructors
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const& src);
		virtual ~AAnimal();
	//Assignment operator
		AAnimal& operator=(AAnimal const& srcs);
	//accessors
		std::string 	getType(void) const;
		void			setType(std::string type);
	//member functions
		virtual void	makeSound() const = 0;
};

