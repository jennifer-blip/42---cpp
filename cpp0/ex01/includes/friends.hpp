/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friends.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:08:40 by jodde             #+#    #+#             */
/*   Updated: 2026/02/10 19:43:33 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>

class	Contact
{
	public :
		std::string	Name, Lastname, Nickname, Phonenumber, Darkest_secret;
};

class	Phonebook
{
	private :
		int		m_max;
		int		m_idx;
		Contact m_c[8];
	public :
		Phonebook() : m_max(8), m_idx(0){}
		void	AddFriend();
		void	SearchFriend();
		void	DisplayContact(int idx);
		void	DisplayList();
};

