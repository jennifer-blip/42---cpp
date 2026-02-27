/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initPB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:08:27 by jodde             #+#    #+#             */
/*   Updated: 2026/02/22 14:23:25 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "friends.hpp"

void	InitPhonebook(void)
{
	Phonebook	friends;
	std::string		cmd;
	
	std::cout<<"Phonebook is empty"<<std::endl;
	std::cout<<"Please enter ADD, SEARCH or EXIT"<<std::endl;
	while (1)
	{
		if(!(std::cin>>cmd))
		    break;
		if (!cmd.compare("ADD"))
			friends.AddFriend();
		if (!cmd.compare("SEARCH"))
			friends.SearchFriend();
		if (!cmd.compare("EXIT"))
			return;
	}
	return;
}

int	main(void)
{
	InitPhonebook();
	return (0);
}