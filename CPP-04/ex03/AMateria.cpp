/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:17:24 by flima             #+#    #+#             */
/*   Updated: 2025/08/24 12:43:56 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
	// std::cout << "AMateria type constructor called." << std::endl;
}

AMateria::AMateria(const AMateria &other): type(other.type) {
	// std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		// std::cout << "AMateria copy assingment constructor called." << std::endl;
	}
	return *this;
}

std::string const& AMateria::getType() const
{
	return type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}