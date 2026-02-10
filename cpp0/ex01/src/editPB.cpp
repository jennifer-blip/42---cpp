/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editPB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:08:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/10 20:37:43 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "friends.hpp"

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
	std::cout<<"Contact successfully added to the phonebook !!!"<<std::endl;
	std::cout<<"Please enter ADD, SEARCH or EXIT"<<std::endl;
}