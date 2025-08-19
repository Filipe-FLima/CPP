/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:40:11 by flima             #+#    #+#             */
/*   Updated: 2025/08/18 14:11:00 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character() : ICharacter(), name("Default"), floor()
{
	for (int i = 0; i < slot; i++)
		inventory[i] = nullptr;
}

Character::Character(const std::string &name) : ICharacter(), name(name), floor()
{
	for (int i = 0; i < slot; i++)
		inventory[i] = nullptr;
}

Character::Character(const Character &other) : ICharacter(), name(other.name),
	floor(other.floor)
{
	for (int i = 0; i < slot; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
	
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		floor = other.floor;
		for (int i = 0; i < slot; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < slot; i++)
	{
		if (inventory[i])
			delete inventory[i];	
	}
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < slot; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= slot)
		return;
	if (inventory[idx])
	{
		floor.dropOnFloor(inventory[idx]);
		inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= slot)
		return;
	if (inventory[idx])
		inventory[idx]->use(target);
}
