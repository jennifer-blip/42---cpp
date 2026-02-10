/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayPB.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:08:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/10 20:31:23 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "friends.hpp"

void	Phonebook::DisplayContact(int idx)
{
	if (idx > std::min(m_idx, m_max) || idx < 1)
	{
		std::cout<<"invalid index, min 1/max 8 contacts in phonebook"<<std::endl;
		return;
	}
	std::cout<<m_c[idx - 1].Name<<std::endl;
	std::cout<<m_c[idx - 1].Lastname<<std::endl;
	std::cout<<m_c[idx - 1].Nickname<<std::endl;
	std::cout<<m_c[idx - 1].Phonenumber<<std::endl;
	std::cout<<m_c[idx - 1].Darkest_secret<<std::endl;
	return;
}
void	FillCell(std::string str)
{
	size_t	len;
	std::string	tmp;

	len = str.length();
		if (len >= 10)
		{
			tmp = str.substr(0,9);
			std::cout<<tmp<<".|";
		}
		else
			std::cout << std::string(10 - len, ' ') << str << "|";
}
void	Phonebook::DisplayList(void)
{
	int	i = 0;
	int	count = 0;

	count = std::min(m_idx, m_max);
	FillCell("index");
	FillCell("First name");
	FillCell("Last Name");
	FillCell("Nickname");
	std::cout<<std::endl;
	while (i < count)
	{
		std::ostringstream oss;
		oss << (i + 1);
		FillCell(oss.str());
		FillCell(m_c[i].Name);
		FillCell(m_c[i].Lastname);
		FillCell(m_c[i].Nickname);
		std::cout<<std::endl;
		i++;
	}
}

void	Phonebook::SearchFriend(void)
{
	int 		idx = 0;
	std::string	ret;
	
	if (m_max == 0)
	{
		std::cout<<"Phonebook is empty, Please enter ADD or EXIT"<<std::endl;
		return;
	}
	DisplayList();
	std::cout<<"Please select index of contact to display or 'QUIT' to return to menu"<<std::endl;
	while (1)
	{
		std::cin>>ret;
		if (ret == "QUIT")
			break;
		std::istringstream iss (ret); // un prompt = une entree utilisateur soit un seul et unique type. ici on attend une string, que l'on convertit au besoin
		if (!(iss >> idx))
		{
            std::cout << "Invalid input" << std::endl;
            continue;
        }
		DisplayContact(idx);
	}
	std::cout<<"Please enter ADD, SEARCH or EXIT"<<std::endl;
	return;
}