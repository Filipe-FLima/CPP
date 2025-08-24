/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:17:49 by flima             #+#    #+#             */
/*   Updated: 2025/08/24 12:31:47 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource(): IMateriaSource()
{
	for(int i = 0; i < slot; i++)
		templates[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other): IMateriaSource()
{
	for(int i = 0; i < slot; i++)
	{
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = nullptr;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		cleanTemplates();
		for(int i = 0; i < slot; i++)
		{
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	cleanTemplates();
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < slot; i++)
	{
		if (!templates[i])
		{
			templates[i] = m->clone();
			delete m;
			m = nullptr;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < slot; i++)
	{
		if (templates[i] && templates[i]->getType() == type)
			return templates[i]->clone();
	}
	return nullptr;
}

void MateriaSource::cleanTemplates()
{
	for(int i = 0; i < slot; i++)
	{
		if (templates[i])
		{
			delete templates[i];
			templates[i] = nullptr;
		}
	}
}
