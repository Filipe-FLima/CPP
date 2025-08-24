/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:08:36 by flima             #+#    #+#             */
/*   Updated: 2025/08/24 12:44:24 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
	// std::cout << "Default Cure constructor called." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	// std::cout << "Cure copy constructor called." << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		// std::cout << "Cure copy assingment constructor called." << std::endl;
	}
	return *this;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called." << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}