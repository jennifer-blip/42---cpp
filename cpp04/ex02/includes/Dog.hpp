/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:58:59 by jodde             #+#    #+#             */
/*   Updated: 2026/03/13 09:15:49 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../includes/Brain.hpp"
#include "../includes/Animal.hpp"

class	Dog : public AAnimal
{
	private :
		std::string		_name;
		Brain*	_brain;
	public :
	//constructors and destructors
		Dog();
		Dog(std::string Name);
		Dog(Dog const& src);
		~Dog();
	//assignment operator
		Dog& operator=(Dog const& src);
	//accessors
		std::string 	getName(void) const;
		void			setName(std::string Name);
	//member function
		void	makeSound() const;
		void	displayIdeas() const;
};
