#include "Dog.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:45:56 by flima             #+#    #+#             */
/*   Updated: 2025/08/10 21:45:57 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Dog::Dog(): Animal()
{
	type = "Dog";
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
	type = "Dog";
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		type = "Dog";
		std::cout << "Dog copy assingment constructor called." << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Auauauauauau..." << std::endl;
}
