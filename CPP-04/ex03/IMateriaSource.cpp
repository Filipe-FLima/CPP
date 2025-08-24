/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:21 by flima             #+#    #+#             */
/*   Updated: 2025/08/24 12:48:23 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	// std::cout << "Default IMateriaSource constructor called." << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &)
{
	// std::cout << "IMateriaSource copy constructor called." << std::endl;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other)
{
	if (this != &other)
	{
		// std::cout << "IMateriaSource copy assingment constructor called." << std::endl;	
	}
	return *this;
}
