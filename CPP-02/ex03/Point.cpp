/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:55:44 by flima             #+#    #+#             */
/*   Updated: 2025/07/30 11:29:30 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float xValue, const float yValue)
 : x(Fixed(xValue)), y(Fixed(yValue))
{
}

Point::Point(const Point &other)
	: x(other.x), y(other.y)
{
}

Point::~Point()
{
}

Point Point::operator-(const Point &other) const
{
	Point toRet((x - other.x), (y - other.y));
	return toRet;
}

Fixed Point::operator*(const Point &other) const
{
	return Fixed(x.toFloat() * other.y.toFloat()) - (y.toFloat() * other.x.toFloat());
}
