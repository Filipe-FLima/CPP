/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:25:55 by flima             #+#    #+#             */
/*   Updated: 2025/07/30 11:22:08 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point AB(b - a);
	Point AP(point - a);
	Point BC(c - b);
	Point BP(point - b);
	Point CA(a - c);
	Point CP(point - c);

	Fixed crossProductA = AB * AP;
	Fixed crossProductB = BC * BP;
	Fixed crossProductC = CA * CP;

	if ((crossProductA.getRawBits() == 0 || crossProductB.getRawBits() == 0 || crossProductC.getRawBits() == 0))
			return false;
	else if ((crossProductA.getRawBits() > 0 && crossProductB.getRawBits() > 0 && crossProductC.getRawBits() > 0) ||
		(crossProductA.getRawBits() < 0 && crossProductB.getRawBits() < 0 && crossProductC.getRawBits() < 0))
			return true;
	return false;
}