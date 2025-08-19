/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:19:45 by flima             #+#    #+#             */
/*   Updated: 2025/08/18 14:28:18 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	// Animal A;
// 	const int size = 4;
// 	Animal *animals[size];
	
// 	for (int i = 0; i < size/2; i++)
// 		animals[i] = new Dog();
// 	for (int i = size/2; i < size; i++)
// 		animals[i] = new Cat();
// 	for (int i = 0; i < size; i++)
// 		delete animals[i];
// 	return 0;
// }

// int main()
// {
// 	Dog basic;
// 	Dog second = basic;
// 	{
// 		Dog tmp = basic;
// 	}
// }

int main()
{
	Animal *AAnimals[10];
	std::cout << "\n=============================================================================\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Round: " << i + 1 << "\n";
		if (i < 5)
			AAnimals[i] = new Dog();
		else
			AAnimals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Round: " << i + 1 << "\n";
		delete (AAnimals[i]);
	}
	std::cout << "\nCiao Rudy!\n\n";
	Dog *Rudy = new Dog();
	Rudy->makeSound();
	// Rudy->getBrain().setIdeas("Rudy's thoughts");
	// Rudy->getBrain().print_first10_ideas();
	delete Rudy;
	std::cout << "\n=============================================================================\n";
	// const AAnimal* meta = new AAnimal(); -> not possible
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Cat* k = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	delete j;
	delete i;
	delete k;
	const WrongAnimal *meta1 = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();
	std::cout << meta1->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	meta1->makeSound();
	wrongcat->makeSound();
	delete meta1;
	delete wrongcat;
	std::cout << "\n=============================================================================\n";
	return (0);
}
