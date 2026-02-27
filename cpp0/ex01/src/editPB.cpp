/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editPB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:08:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/22 11:35:34 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "friends.hpp"
#include <string>
#include <iostream>

int CheckEmptyLine(const std::string &prompt, std::string& ret)
{
    size_t      start;
    size_t      end;
    bool        valid_entry = false;
    
    while (!valid_entry)
    {
        std::cout << prompt << std::endl;
        if (!std::getline(std::cin, ret))
        {
            std::cout << "\nEOF detected. Exiting." << std::endl;
            return (0);
        }
        start = ret.find_first_not_of(" \t");
        end = ret.find_last_not_of(" \t");
        if (start == std::string::npos)
            std::cout << "Input cannot be empty. Please try again." << std::endl;
        else
        {
            ret = ret.substr(start, end - start + 1);
            valid_entry = true;
        }
    }
    return (1);
}


void	Phonebook::AddFriend(void)
{
	int	i;
    std::string input;

	i = m_idx % m_max;
    std::cin.ignore();
	if (!CheckEmptyLine("Enter Name", input))
        return ;
    m_c[i].SetName(input);
	if (!CheckEmptyLine("Enter Last name", input))
        return ;
    m_c[i].SetLastname(input);
	if (!CheckEmptyLine("Enter Nickname", input))
        return ;
    m_c[i].SetNickname(input);
	if (!CheckEmptyLine("Enter Phonenumber", input))
        return ;
    m_c[i].SetPhonenumber(input);
	if (!CheckEmptyLine("Enter Darkest secret", input))
        return ;
    m_c[i].SetDarkest_secret(input);
	m_idx++;
	std::cout<<"Contact successfully added to the phonebook !!!"<<std::endl;
	std::cout<<"Please enter ADD, SEARCH or EXIT"<<std::endl;
}