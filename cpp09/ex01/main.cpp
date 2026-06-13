/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:31:08 by jodde             #+#    #+#             */
/*   Updated: 2026/06/13 12:29:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"


int main (int argc, char **argv)
{
	if (argc < 2)
		return (logError("Error : args : expected 'reverse polish notation calculation'"), 1);
	RPN rpn(argv[1]);
	try {
		// rpn.checkArg();
		rpn.fillStack();
		// rpn.displayStack();
		rpn.calculate();
	} 
	catch (std::exception& e) {std::cerr << e.what() << std::endl;}
	return (0);
}