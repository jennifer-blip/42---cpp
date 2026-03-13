/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:01:35 by jodde             #+#    #+#             */
/*   Updated: 2026/03/13 09:09:32 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	{
		display("42 SUBJECT TEST", RED);
		const Animal* meta = new Animal();
		const Animal* j = new Dog("Max");
		const Dog* d = dynamic_cast<const Dog*> (j);
		std::cout << j->getType() << " " << std::endl;
		std::cout << d->getName() << " " << std::endl;
		d->displayIdeas();
		delete meta;
		delete j;
		display("END OF 42 SUBJECT TEST", BROWN);
	}
	{
		display("DOG DEEPCOPY TEST", RED);
		Dog basic;
		basic.displayIdeas();
		{
			Dog tmp = basic;
			tmp.displayIdeas();
		}
	{
		display("CAT DEEPCOPY TEST", RED);
		Cat basic;
		basic.displayIdeas();
		{
			Cat tmp = basic;
			tmp.displayIdeas();
		}
	}
	}
	display("END OF DEEPCOPY TEST", BROWN);
}
