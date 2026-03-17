/* ************************************************************************** */
/*                                                                            */
/*                           	                          :::      ::::::::   */
/*   Cure.hpp           	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:54:04 by jodde             #+#    #+#             */
/*   Updated: 2026/03/16 08:45:31 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		//Constructors and destructors
		Cure();
		Cure(std::string const & type);
		Cure(Cure const& src);
		~Cure();
		//assignment operator
		Cure&	operator=(Cure const& src);
		//Member functions
		Cure*	clone() const;
		void	use(ICharacter& target);
};
