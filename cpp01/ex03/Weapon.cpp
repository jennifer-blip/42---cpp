/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:24:40 by jodde             #+#    #+#             */
/*   Updated: 2026/02/15 17:21:11 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void	Weapon::setType(std::string newType) 
{
	this->_type = newType;
}

std::string	Weapon::getType(void) const
{
	return(this->_type);
}
