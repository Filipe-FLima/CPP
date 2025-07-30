/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:53:24 by flima             #+#    #+#             */
/*   Updated: 2025/07/30 11:29:36 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point();
	Point(const float xValue, const float yValue);
	Point(const Point& other);
	Point& operator=(const Point& other) = delete;
	~Point();
	Point	operator-(const Point& other) const;
	Fixed	operator*(const Point& other) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif