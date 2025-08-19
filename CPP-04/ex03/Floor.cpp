
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:52:56 by flima             #+#    #+#             */
/*   Updated: 2025/08/17 18:52:57 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Floor.hpp"

Floor::Floor() : onFloor(0)
{
	for (int i = 0; i < FLOOR_LIM; i++)
		floor[i] = nullptr;
}

Floor::Floor(const Floor &other)
{
	onFloor = other.onFloor;
	for (int i = 0; i < FLOOR_LIM; i++)
	{
		if (other.floor[i])
			floor[i] = other.floor[i]->clone();
		else
			floor[i] = nullptr;
	}
}

Floor &Floor::operator=(const Floor &other)
{
	if (this != &other)
	{
		cleanFloor();
		onFloor = other.onFloor;
		for (int i = 0; i < FLOOR_LIM; i++)
		{
			if (other.floor[i])
				floor[i] = other.floor[i]->clone();
			else
				floor[i] = nullptr;
		}
	}
	return *this;
}

Floor::~Floor()
{
	cleanFloor();
}

void Floor::dropOnFloor(AMateria *m)
{
	if (onFloor == FLOOR_LIM)
		cleanFloor();
	for (int i = 0; i < FLOOR_LIM; i++)
	{
		if (!floor[i])
		{
			floor[i] = m;
			onFloor++;
			break;
		}
	}
}

void Floor::cleanFloor()
{
	for (int i = 0; i < FLOOR_LIM; i++)
	{
		if (floor[i])
		{
			delete floor[i];
			floor[i] = nullptr;
		}
	}
	onFloor = 0;
}
