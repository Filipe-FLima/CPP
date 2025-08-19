/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:39:20 by flima             #+#    #+#             */
/*   Updated: 2025/08/15 11:02:20 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	catBrain = new Brain();
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
	type = "Cat";
	catBrain = new Brain(*other.catBrain);
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		type = "Cat";
		catBrain = new Brain(*catBrain);
		std::cout << "Cat copy assingment constructor called." << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	delete catBrain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miauuuuuu..." << std::endl;
}
