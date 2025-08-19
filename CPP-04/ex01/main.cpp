/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:19:45 by flima             #+#    #+#             */
/*   Updated: 2025/08/15 11:21:20 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const int size = 4;
	Animal *animals[size];
	
	for (int i = 0; i < size/2; i++)
		animals[i] = new Dog();
	for (int i = size/2; i < size; i++)
		animals[i] = new Cat();
	for (int i = 0; i < size; i++)
		delete animals[i];
	return 0;
}
