/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:02:28 by flima             #+#    #+#             */
/*   Updated: 2025/07/19 15:34:03 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}