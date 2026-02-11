/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editPB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:08:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/11 10:25:10 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "friends.hpp"
#include <string>
#include <iostream>

std::string CheckEmptyLine(const std::string &prompt)
{
    std::string ret;
    size_t      start;
    size_t      end;
    
    while (true)
    {
        std::cout << prompt << std::endl;
        std::getline(std::cin, ret);
        start = ret.find_first_not_of(" \t");
        end = ret.find_last_not_of(" \t");
        if (start == std::string::npos)
        {
            std::cout << "Input cannot be empty. Please try again." << std::endl;
            continue;
        }
        ret = ret.substr(start, end - start + 1);
        break;
    }
    return (ret);
}


void	Phonebook::AddFriend(void)
{
	int	i;

	i = m_idx % m_max;
    std::cin.ignore();
	m_c[i].Name = CheckEmptyLine("Enter Name");
	m_c[i].Lastname = CheckEmptyLine("Enter Last name");
	m_c[i].Nickname = CheckEmptyLine("Enter Nickname");
	m_c[i].Phonenumber = CheckEmptyLine("Enter Phonenumber");
	m_c[i].Darkest_secret = CheckEmptyLine("Enter Darkest secret");
	m_idx++;
	std::cout<<"Contact successfully added to the phonebook !!!"<<std::endl;
	std::cout<<"Please enter ADD, SEARCH or EXIT"<<std::endl;
}