#include "ClapTrap.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:29:24 by flima             #+#    #+#             */
/*   Updated: 2025/07/31 11:29:25 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(STATS), 
	energyPoints(STATS * ENERGY), attackDamage(STATS * ATK),
	outOfEnergy(false)
{
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(STATS), 
	energyPoints(STATS * ENERGY), attackDamage(STATS * ATK),
	outOfEnergy(false)
{
	std::cout << "Name constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints != 0)
	{
		energyPoints--;
		std::cout << "\nClapTrap " << name << " attacks ClapTrap " << target << " causing "
			<< attackDamage << " points of damage." << std::endl; 
	}
	else
	{
		std::cout << "\nClapTrap " << name << " is out of energy points, it can not attack." << std::endl;
		outOfEnergy = true;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int damage;

	if (hitPoints != 0)
	{
		if (hitPoints > amount)
			damage = amount;
		else
			damage = hitPoints;
		hitPoints -= damage;
		std::cout << "\nClapTrap " << name << " took " << damage << " points of damage." << std::endl
			<< "ClapTrap " << name << " has " << getHitPoints() << " hitPoints" << std::endl;
	}
	else
		std::cout << "\nClapTrap " << name << " has been knocked out!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints != 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "\nClapTrap " << name << " repaired " << amount << " points of hitPoints." << std::endl
			<< "ClapTrap " << name << " has " << getEnergyPoints() << " energy points" << std::endl;
	}
	else
		std::cout << "\nClapTrap " << name << " is out of energy points"
		", it can not be repaired." << std::endl;
}

const std::string &ClapTrap::getName() const
{
	return name;
}

bool ClapTrap::checkEnergy()
{
	return outOfEnergy;
}

unsigned int ClapTrap::getHitPoints()
{
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints()
{
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage()
{
	return attackDamage;
}

bool ClapTrap::is_alive()
{
	if (getEnergyPoints() == 0 && getHitPoints() == 0)
		return false;
	return true;
}
