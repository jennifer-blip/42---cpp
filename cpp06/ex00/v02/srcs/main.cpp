/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:57:15 by jodde             #+#    #+#             */
/*   Updated: 2026/05/17 18:12:44 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include "../includes/ScalarConverter.hpp"
#include "../includes/display.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (display("ERROR - ARGS = ./convert [number]", RED), 1);
	ScalarConverter::convert(argv[1]);
	return(0);
}