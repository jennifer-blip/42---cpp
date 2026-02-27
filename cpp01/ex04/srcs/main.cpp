/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:48:48 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 10:50:53 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include "error.hpp"

int main(int argc, char **argv)
{
	if (argc < 4)
		return (error("ARGS: <filename> <string1> <string2>"), 1);
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string file = argv[1];
	if (s1.empty())
		return (error("ARGS: <string1> should not be empty"), 1);
	replaceString(file, s1, s2);
	return (0);
}
