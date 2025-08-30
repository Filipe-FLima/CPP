/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:17:27 by flima             #+#    #+#             */
/*   Updated: 2025/08/30 12:16:35 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	std::cout << "Character name: " << me->getName() << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << "Materia type: " << tmp->getType() << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	std::cout << "Materia type: " << tmp->getType() << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("ice");
	std::cout << "Materia type: " << tmp->getType() << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	std::cout << "Materia type: " << tmp->getType() << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("ice");
	std::cout << "Materia type: " << tmp->getType() << std::endl;
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	std::cout << "Materia type: " << tmp->getType() << std::endl;
	me->equip(tmp);
	delete tmp;
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(5, *bob);

	IMateriaSource *src2 = new MateriaSource();

	*src2 = *src;
	*bob = *me;
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	delete bob;
	delete me;
	delete src;
	delete src2;
	
	return 0;
}