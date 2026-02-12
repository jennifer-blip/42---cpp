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
	_nbAccounts++;
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);	
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);	
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	displayStatus;
}

//Non-static functions

void	Account::makeDeposit( int deposit )
{

	_amount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	
}
int		Account::checkAmount( void ) const
{
	
}
void	Account::displayStatus( void ) const
{
	if (_accountIndex < _nbAccounts)
	{
		std::cout<<"index:"<<_accountIndex<<";";
		std::cout<<"amount:"<<_amount<<";";
		std::cout<<"deposits:"<<_nbDeposits<<";";
		std::cout<<"withdrawals:"<<_nbWithdrawals<<std::endl;
	}
	else
	{
		std::cout<<"accounts:"<<_nbAccounts<<";";
		std::cout<<"total:"<<getTotalAmount()<<";";
		std::cout<<"deposits:"<<getNbDeposits()<<";";
		std::cout<<"withdrawals:"<<getNbWithdrawals()<<std::endl;
	}
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
	_accountIndex = _nbAccounts;
	makeDeposit(initial_deposit);
	getNbAccounts();
	std::cout<<"index:"<<_accountIndex<<";";
	std::cout<<"amount:"<<_amount<<";";
	std::cout<<"created"<<";"<<std::endl;
}
Account::~Account( void )
{
	std::cout<<"Account destroyed"<<std::endl;
}