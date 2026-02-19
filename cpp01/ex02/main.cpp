/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:48:24 by jodde             #+#    #+#             */
/*   Updated: 2026/02/15 16:17:33 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<string>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string& stringREF = string;
	
	std::cout<<"The memory address of the string variable is : "<<&string<<std::endl;
	std::cout<<"The memory address held by stringPTR is : "<<stringPTR<<std::endl;
	std::cout<<"The memory address held by stringREF is : "<<&stringREF<<std::endl;
	
	std::cout<<"The value of the string variable is : "<<string<<std::endl;
	std::cout<<"The value pointed to by stringPTR is : "<<*stringPTR<<std::endl;
	std::cout<<"The value pointed to by stringREF is : "<<stringREF<<std::endl;
	
	return (0);
}
