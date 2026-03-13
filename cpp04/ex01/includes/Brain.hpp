/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:13:03 by jodde             #+#    #+#             */
/*   Updated: 2026/03/13 08:46:52 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../includes/Animal.hpp"

class	Brain
{
	private :
		std::string _ideas[100];
	public :
	//Constructors and destructors
		Brain();
		Brain(std::string type);
		Brain(Brain const& src);
		~Brain();
	//Assignment operator
		Brain& operator=(Brain const& src);
	//Accessors
		std::string*	getIdeas(void);
		void			setIdeas(std::string type);
};
