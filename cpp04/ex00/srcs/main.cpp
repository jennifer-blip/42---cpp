/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:01:35 by jodde             #+#    #+#             */
/*   Updated: 2026/03/12 08:38:37 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/display.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	{
		display("42 SUBJECT TEST", RED);
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	{
		display("WRONGANIMAL TEST", RED);
		const WrongAnimal* wrongmeta = new WrongAnimal();
		const Animal* meta = new Animal();
		const WrongAnimal* j = new WrongCat();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the animal (wrongcat) sound!
		j->makeSound(); //will output the cat sound
		meta->makeSound();
		wrongmeta->makeSound();
		delete wrongmeta;
		delete meta;
		delete i;
		delete j;
	}
}
