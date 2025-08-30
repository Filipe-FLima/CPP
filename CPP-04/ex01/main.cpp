/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:19:45 by flima             #+#    #+#             */
/*   Updated: 2025/08/29 12:15:49 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const int size = 4;
	Animal *animals[size];
	Dog A;
	Dog B;
	Cat a;
	Cat b;
	
	Dog basic;
	{
		Dog tmp = basic;
	}
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	B = A;
	a = b;
	for (int i = 0; i < size/2; i++)
		animals[i] = new Dog();
	for (int i = size/2; i < size; i++)
		animals[i] = new Cat();
	for (int i = 0; i < size; i++)
		delete animals[i];
	return 0;
}
