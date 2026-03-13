/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:58:44 by jodde             #+#    #+#             */
/*   Updated: 2026/03/12 13:05:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

class	Cat : public Animal
{
	private :
		std::string 	_name;
		Brain*	_brain;
	public :
	//constructors and destructors
		Cat();
		Cat(std::string Name);
		Cat(Cat const& src);
		~Cat();
	//assignment operator
		Cat& operator=(Cat const& src);
	//accessors
		std::string getName(void) const;
		void		setName(std::string Name);
	//member function
		void	makeSound() const;
		void	displayIdeas() const;
};
