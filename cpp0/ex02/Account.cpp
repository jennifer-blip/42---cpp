/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:18:21 by jodde             #+#    #+#             */
/*   Updated: 2026/02/12 12:33:21 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include "Account.hpp"

//static functions

int	Account::getNbAccounts( void )
{
	
}
int	Account::getTotalAmount( void )
{

}
int	Account::getNbDeposits( void )
{
	
}
int	Account::getNbWithdrawals( void )
{
	
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
}

//Non-static functions

void	Account::makeDeposit( int deposit )
{

}
bool	Account::makeWithdrawal( int withdrawal )
{
	
}
int		Account::checkAmount( void ) const
{
	
}
void	Account::displayStatus( void ) const
{
	
}

//Timestamp

void	Account::_displayTimestamp( void )
{
	std::time_t	now = std::time(NULL);
	std::tm		*timeinfo = std::localtime(&now);//pas multithread safe
	// std::tm		*result; //thread safe mais pas standard c++98
	char		buffer[20];
	
	// localtime_r(&now, result); //thread safe mais pas standard c++98
	std::strftime (buffer, 20, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout<<buffer<<" ";
}

//Constructeur et destructeur
Account::Account( int initial_deposit )
{
	Account();
	makeDeposit(initial_deposit);
	std::cout<<"Account created and credited with"<< initial_deposit<<std::endl;
}
Account::~Account( void )
{
	std::cout<<"Account destroyed"<<std::endl;
}