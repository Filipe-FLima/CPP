/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:40:48 by flima             #+#    #+#             */
/*   Updated: 2025/08/24 12:46:54 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice()
{
	type = "ice";
	// std::cout << "Default Ice constructor called." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	// std::cout << "Ice copy constructor called." << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		// std::cout << "Ice copy assingment constructor called." << std::endl;
	}
	return *this;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called." << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
