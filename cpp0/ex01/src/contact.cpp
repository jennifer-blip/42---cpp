/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:17:34 by jodde             #+#    #+#             */
/*   Updated: 2026/02/22 14:21:43 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "friends.hpp"

void	Contact::SetName(std::string name){	this->_name = name;}

void	Contact::SetLastname(std::string lastname){	this->_lastname = lastname;}

void	Contact::SetNickname(std::string nickname){	this->_nickname = nickname;}

void	Contact::SetPhonenumber(std::string phonenumber){ this->_phonenumber = phonenumber;}

void	Contact::SetDarkest_secret(std::string darkest_secret){	this->_darkest_secret = darkest_secret;}

std::string	Contact::GetName(){	return (this->_name);}

std::string	Contact::GetLastname(){	return (this->_lastname);}

std::string	Contact::GetNickname(){	return (this->_nickname);}

std::string	Contact::GetPhonenumber(){	return (this->_phonenumber);}

std::string	Contact::GetDarkest_secret(){	return (this->_darkest_secret);}