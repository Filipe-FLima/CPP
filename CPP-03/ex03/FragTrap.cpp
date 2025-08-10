#include "FragTrap.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:07:35 by flima             #+#    #+#             */
/*   Updated: 2025/08/07 20:07:36 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	hitPoints = STATS * FRAG_HP;
	Frag_hitPoints = STATS * FRAG_HP;
	energyPoints = STATS * FRAG_ENGY;
	attackDamage = STATS * FRAG_ATTACK;
	Frag_attackDamage = STATS * FRAG_ATTACK;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "FragTrap name constructor called." << std::endl;
	hitPoints = STATS * FRAG_HP;
	Frag_hitPoints = STATS * FRAG_HP;
	energyPoints = STATS * FRAG_ENGY;
	attackDamage = STATS * FRAG_ATTACK;
	Frag_attackDamage = STATS * FRAG_ATTACK;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy assignment constructor called." << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (energyPoints != 0)
	{
		energyPoints--;
		std::cout << "\nFragTrap " << name << " attacks " << target << " causing "
			<< attackDamage << " points of damage." << std::endl; 
	}
	else
	{
		std::cout << "\nFragTrap " << name << " is out of energy points, it can not attack." << std::endl;
		outOfEnergy = true;
	}
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap: High five detected! ✋ Engage in celebration protocol!" << std::endl;
}
