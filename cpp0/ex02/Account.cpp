/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:18:21 by jodde             #+#    #+#             */
/*   Updated: 2026/02/22 14:41:22 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"
#define BLUE "\033[34m"
#define RESET "\033[0m"

//definition des variables statiques de la classe Account
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//static functions
int	Account::getNbAccounts( void ){	return (_nbAccounts);}
int	Account::getTotalAmount( void ){ return (_totalAmount);}
int	Account::getNbDeposits( void ){	return (_totalNbDeposits);}
int	Account::getNbWithdrawals( void ){ return (_totalNbWithdrawals);}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<"accounts:"<<BLUE<<getNbAccounts()<<RESET<<";";
	std::cout<<"total:"<<BLUE<<getTotalAmount()<<RESET<<";";
	std::cout<<"deposits:"<<BLUE<<getNbDeposits()<<RESET<<";";
	std::cout<<"withdrawals:"<<BLUE<<getNbWithdrawals()<<RESET<<std::endl;
}

//Non-static functions
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout<<"index:"<<BLUE<<_accountIndex<<RESET<<";";
	std::cout<<"p_amount:"<<BLUE<<_amount<<RESET";";
	_amount += deposit;
	_nbDeposits++;
	std::cout<<"deposit:"<<BLUE<<deposit<<RESET<<";";
	std::cout<<"amount:"<<BLUE<<_amount<<RESET<<";";
	std::cout<<"nb_deposits:"<<BLUE<<_nbDeposits<<RESET<<std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout<<"index:"<<BLUE<<_accountIndex<<RESET<<";";
	std::cout<<"p_amount:"<<BLUE<<_amount<<RESET<<";";
	if (checkAmount() >= withdrawal)
	{
		std::cout<<"withdrawals:"<<BLUE<<withdrawal<<RESET<<";";
		_amount -= withdrawal;
		std::cout<<"amount:"<<BLUE<<_amount<<RESET<<";";
		_nbWithdrawals++;
		std::cout<<"nb_withdrawals:"<<BLUE<<_nbWithdrawals<<RESET<<std::endl;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout<<"p_amount:"<<BLUE<<_amount<<RESET<<";";
		std::cout<<"withdrawals:"<<BLUE<<"refused"<<RESET<<std::endl;
		return (false);
	}
}
int		Account::checkAmount( void ) const{	return (_amount);}

void	Account::displayStatus( void ) const
{
		_displayTimestamp();
		std::cout<<"index:"<<BLUE<<_accountIndex<<RESET<<";";
		std::cout<<"amount:"<<BLUE<<_amount<<RESET<<";";
		std::cout<<"deposits:"<<BLUE<<_nbDeposits<<RESET<<";";
		std::cout<<"withdrawals:"<<BLUE<<_nbWithdrawals<<RESET<<std::endl;
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

Account::Account(void) { }

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout<<"index:"<<BLUE<<_accountIndex<<RESET<<";";
	std::cout<<"amount:"<<BLUE<<_amount<<RESET<<";";
	std::cout<<"created"<<std::endl;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout<<"index:"<<BLUE<<_accountIndex<<RESET<<";";
	std::cout<<"amount:"<<BLUE<<_amount<<RESET<<";";
	std::cout<<"closed"<<std::endl;
}