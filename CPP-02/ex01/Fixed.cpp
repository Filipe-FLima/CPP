#include "Fixed.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:38:54 by flima             #+#    #+#             */
/*   Updated: 2025/07/25 18:38:55 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointN(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &value)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointN = value << fractionalBit;
}

Fixed::Fixed(const float &value)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointN = roundf(value * (1 << fractionalBit));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPointN = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointN = other.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointN;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointN = raw;
}

float Fixed::toFloat(void) const
{
	float value = fixedPointN / (1 << fractionalBit);
	return value;
}

int Fixed::toInt(void) const
{
	int value = fixedPointN >> fractionalBit;
	return value;
}
