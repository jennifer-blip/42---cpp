/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:49:05 by jodde             #+#    #+#             */
/*   Updated: 2026/02/19 14:00:37 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	replaceString (std::ofstream& outfile, std::string buf, std::string& s1, std::string& s2)
{
	size_t	pos;
	
	if (buf.empty())
		return;
	pos = buf.find(s1, 0);
	while (pos != std::string::npos)
	{
		buf.erase(pos, s1.length());
		buf.insert(pos, s2);
		pos += s2.length();
		pos = buf.find(s1, pos);
	}
	outfile << buf;
	return;
}