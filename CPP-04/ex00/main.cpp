/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:19:45 by flima             #+#    #+#             */
/*   Updated: 2025/08/30 11:46:47 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();

	const Animal* META = new Animal();
	const Animal* J = new Dog();
	const Animal* I = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << J->getType() << " " << std::endl;
	std::cout << I->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	I->makeSound();
	J->makeSound();
	META->makeSound();
	
	delete meta;
	delete j;
	delete i;
	delete META;
	delete J;
	delete I;
	return 0;
}
