/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:58:44 by jodde             #+#    #+#             */
/*   Updated: 2026/03/11 12:08:58 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../includes/WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	private :
		std::string _name;
	public :
	//constructors and destructors
		WrongCat();
		WrongCat(std::string Name);
		WrongCat(WrongCat const& src);
		~WrongCat();
	//assignment operator
		WrongCat& operator=(WrongCat const& src);
	//accessors
		std::string getName(void) const;
		void		setName(std::string Name);
	//member function
		void	makeSound() const;
};
