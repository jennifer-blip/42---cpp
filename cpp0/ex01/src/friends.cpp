/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friends.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:08:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/10 12:17:20 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "friends.hpp"

void	FillCell(std::string str)
{
	size_t	len;
	std::string	tmp;

	len = str.length();
		if (len >= 10)
		{
			tmp = str.substr(0,9);
			tmp += ".";
			std::cout<<tmp<<"|";
		}
		else
			std::cout<<str.append(10 - len, ' ')<<"|";
}

void	Phonebook::SearchFriend(void)
{
	int	i = 0;
	int	count = 0;

	if (m_max == 0)
	{
		std::cout<<"Phonebook is empty, Please enter ADD or EXIT"<<std::endl;
		return;
	}
	count = std::min(m_idx, m_max);
	while (i < count)
	{
		FillCell("index");
		FillCell("First name");
		FillCell("Last Name");
		FillCell("Nickname");
		std::cout<<std::endl;
		std::cout<<i<<"         "<<"|";
		FillCell(m_c[i].Name);
		FillCell(m_c[i].Lastname);
		FillCell(m_c[i].Nickname);
		std::cout<<std::endl;
		i++;
	}
}

void	Phonebook::AddFriend(void)
{
	int	i;

	i = m_idx % m_max;
	std::cout<<"Enter Name"<<std::endl;
	std::cin>>m_c[i].Name;
	std::cout<<"Enter LastName"<<std::endl;
	std::cin>>m_c[i].Lastname;
	std::cout<<"Enter NickName"<<std::endl;
	std::cin>>m_c[i].Nickname;
	std::cout<<"Enter Phonenumber"<<std::endl;
	std::cin>>m_c[i].Phonenumber;
	std::cout<<"Enter Darkest_secret"<<std::endl;
	std::cin>>m_c[i].Darkest_secret;
	m_idx++;
}

void	InitPhonebook(void)
{
	Phonebook	friends;
	std::string		cmd;
	
	std::cout<<"Phonebook is empty";
	std::cout<<"Please enter ADD, SEARCH or EXIT"<<std::endl;
	while (1)
	{
		std::cin>>cmd;
		if (!cmd.compare("ADD"))
			friends.AddFriend();
		if (!cmd.compare("SEARCH"))
			friends.SearchFriend();
		if (!cmd.compare("EXIT"))
			return;
	}
}

int	main(void)
{
	InitPhonebook();
	return (0);
}