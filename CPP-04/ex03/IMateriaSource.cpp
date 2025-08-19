/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:21 by flima             #+#    #+#             */
/*   Updated: 2025/08/18 14:13:58 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "Default IMateriaSource constructor called." << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &)
{
	std::cout << "IMateriaSource copy constructor called." << std::endl;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &)
{
	std::cout << "IMateriaSource copy assingment constructor called." << std::endl;
	return *this;
}
