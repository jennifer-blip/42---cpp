/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:48:48 by jodde             #+#    #+#             */
/*   Updated: 2026/02/19 14:03:17 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<replace.hpp>

int	check_args(int argc)
{
	if (argc < 4)
	{
		std::cout<<"ERROR : ARGS: <filename> <string1> <string2>"<<std::endl;
		return (1);
	}
	return (0);
}
int	check_file(std::ifstream& fs)
{
	if (!fs.good())
	{
		std::cout<<"ERROR : FILE: cannot open file"<<std::endl;
		return (1);
	}
	return (0);
}

int	check_string(std::string s)
{
	if (s.empty())
	{
		std::cout<<"ERROR : ARGS: <string1> should not be empty"<<std::endl;
		return (1);
	}
	return (0);
}
int	main(int argc, char **argv)
{
	if (check_args (argc))
		return (1);
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	file = argv[1];
	
	if (check_string(s1))
		return (1);
	
	std::ifstream infile(argv[1]);
	if (check_file(infile))
		return (1);
	
	std::string	outfn = file + ".replace";
	std::ofstream outfile(outfn.c_str());

	std::string	buf;
	while (getline(infile, buf))
		replaceString(outfile, buf + '\n', s1, s2);
	infile.close();
	outfile.close();
	return (0);
}