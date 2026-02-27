/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:49:05 by jodde             #+#    #+#             */
/*   Updated: 2026/02/25 11:58:09 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include "error.hpp"

void	replaceString (std::string filename, std::string& s1, std::string& s2)
{
	size_t		pos;
	std::string buf;
	std::string	outfn = filename + ".replace";
	
	std::ifstream infile(filename.c_str());
	if (!infile.good())
		return (error("ARGS: cannot open infile"));
	
	std::ofstream outfile(outfn.c_str());
	if (!outfile.good())
		return (error("cannot open outfile"));

	getline(infile, buf, '\0');
	while ((pos=buf.find(s1, 0)) != std::string::npos)
	{
		buf.erase(pos, s1.length());
		buf.insert(pos, s2);
		pos += s2.length();
	}
	outfile << buf;
	infile.close();
	outfile.close();
	return;
}
