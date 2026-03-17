/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:54:04 by jodde             #+#    #+#             */
/*   Updated: 2026/03/16 17:39:20 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		//Constructors and destructors
		Ice();
		Ice(std::string const & type);
		Ice(Ice const& src);
		~Ice();
		//assignment operator
		Ice&	operator=(Ice const& src);
		//Member functions
		Ice*	clone() const;
		void	use(ICharacter& target);
};
