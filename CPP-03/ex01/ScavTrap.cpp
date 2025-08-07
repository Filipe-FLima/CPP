#include "ScavTrap.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:05:09 by flima             #+#    #+#             */
/*   Updated: 2025/08/05 20:05:10 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called." << std::endl;
	hitPoints = STATS * HP;
	energyPoints = STATS * ENGY;
	attackDamage = STATS * ATTACK;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->ClapTrap::operator=(other);
		std::cout << "ScavTrap copy assignment called." << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate kepper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints != 0)
	{
		energyPoints--;
		std::cout << "\nScavTrap " << name << " attacks " << target << " causing "
			<< attackDamage << " points of damage." << std::endl; 
	}
	else
	{
		std::cout << "\nScavTrap " << name << " is out of energy points, it can not attack." << std::endl;
		outOfEnergy = true;
	}
}

