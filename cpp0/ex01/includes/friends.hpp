/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friends.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:08:40 by jodde             #+#    #+#             */
/*   Updated: 2026/02/21 17:19:50 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>

class	Contact
{
	private :
		std::string	_name, _lastname, _nickname, _phonenumber, _darkest_secret;
	public :
		void	SetName(std::string name);
		void	SetLastname(std::string lastname);
		void	SetNickname(std::string nickname);
		void	SetPhonenumber(std::string phonenumber);
		void	SetDarkest_secret(std::string darkest_secret);

		std::string	GetName();
		std::string	GetLastname();
		std::string	GetNickname();
		std::string	GetPhonenumber();
		std::string	GetDarkest_secret();
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

