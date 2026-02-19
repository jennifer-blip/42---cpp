/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:48:58 by jodde             #+#    #+#             */
/*   Updated: 2026/02/19 13:19:18 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

void	replaceString (std::ofstream& outfile, std::string buf, std::string& s1, std::string& s2);