/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:04:15 by flima             #+#    #+#             */
/*   Updated: 2025/08/10 21:09:45 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->name = "Default";
	this->hitPoints = Frag_hitPoints;
	this->energyPoints = Scav_energyPoints;
	this->attackDamage = Frag_attackDamage;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"),
	 ScavTrap(_name), FragTrap(_name + "_clap_name")
{
	std::cout << "DiamondTrap name constructor called." << std::endl;
	this->name = _name;
	this->hitPoints = Frag_hitPoints;
	this->energyPoints = Scav_energyPoints;
	this->attackDamage = Frag_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	name = other.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
		std::cout << "DiamondTrap copy assignment constructor called." << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " has been destroyed" << std::endl;
}

const std::string &DiamondTrap::getDiamondName() const
{
	return name;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name 
		<< std::endl << "ClapTrap name: " << ClapTrap::name <<std::endl;
}
