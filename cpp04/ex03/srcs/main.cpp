/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:59:22 by jodde             #+#    #+#             */
/*   Updated: 2026/03/17 16:29:36 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/display.hpp"

int main()
{
	{
		display("//////42 SUBJECT TEST/////", RED);
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		display("//////END OF TEST/////", RED);
	}
	{
		display("//////MATERIA SOURCE TEST/////", RED);
		IMateriaSource* grimoire = new MateriaSource();
		grimoire->learnMateria(new Ice());
		grimoire->learnMateria(new Cure());
		grimoire->learnMateria(new Cure());
		grimoire->learnMateria(new Ice());
		grimoire->learnMateria(new Ice());
		delete grimoire;
		display("//////END OF TEST/////", RED);
	}
	{
		display("//////CHARACTER TEST/////", RED);
		IMateriaSource* grimoire = new MateriaSource();
		grimoire->learnMateria(new Ice());
		grimoire->learnMateria(new Cure());
		ICharacter* gandalf = new Character("gandalf");
		AMateria* tmp;
		tmp = grimoire->createMateria("cure");
		gandalf->equip(tmp);
		tmp = grimoire->createMateria("ice");
		gandalf->equip(tmp);
		tmp = grimoire->createMateria("ice");
		gandalf->equip(tmp);
		tmp = grimoire->createMateria("ice");
		gandalf->equip(tmp);
		tmp = grimoire->createMateria("ice");
		gandalf->equip(tmp);
		ICharacter* sauron = new Character("sauron");
		gandalf->use(0, *sauron);
		gandalf->use(1, *sauron);
		gandalf->use(2, *sauron);
		gandalf->use(3, *sauron);
		gandalf->use(4, *sauron);
		gandalf->unequip(2);
		delete sauron;
		delete gandalf;
		delete grimoire;
		display("//////END OF ALL TESTS/////", RED);
	}
}
