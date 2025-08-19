/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:23:42 by flima             #+#    #+#             */
/*   Updated: 2025/08/18 14:13:50 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "Default ICharacter constructor called." << std::endl;
}

ICharacter::ICharacter(const ICharacter &)
{
	std::cout << "ICharacter copy constructor called." << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &)
{
	std::cout << "ICharacter copy assingment constructor called." << std::endl;
	return *this;
}
