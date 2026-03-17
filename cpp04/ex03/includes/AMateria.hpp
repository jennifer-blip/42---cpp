/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:48:38 by jodde             #+#    #+#             */
/*   Updated: 2026/03/16 17:55:09 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
			
	public:
		//Constructors and destructors
		AMateria(std::string const & type);
		AMateria(AMateria const& src);
		virtual ~AMateria();
		//assignment operator
		AMateria&	operator=(AMateria const& src);
		//Accessors
			std::string const &	getType() const;
		//Member functions
			virtual AMateria*	clone() const = 0;
			virtual void		use(ICharacter& target);
};
