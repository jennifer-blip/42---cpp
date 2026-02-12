/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:34:19 by jodde             #+#    #+#             */
/*   Updated: 2026/02/08 18:46:19 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	print_upper(const char *s)
{
	int	i;
	char	u;

	i = 0;
	u = 0;
	while(s[i])
	{
		u = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
		std::cout << u;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < (argc - 1))
		print_upper(argv[i++]);
	if (i == (argc - 1))
	{
		print_upper(argv[i]);
		std::cout << std::endl;
	}
	return (1);
}

