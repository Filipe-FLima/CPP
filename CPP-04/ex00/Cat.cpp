/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:39:20 by flima             #+#    #+#             */
/*   Updated: 2025/08/13 12:08:31 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
	type = "Cat";
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		type = "Cat";
		std::cout << "Cat copy assingment constructor called." << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miauuuuuu..." << std::endl;
}
