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
}

Fixed::Fixed(const int &value)
{
	fixedPointN = value << fractionalBits;
}

Fixed::Fixed(const float &value)
{
	fixedPointN = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	fixedPointN = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->fixedPointN = other.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->fixedPointN;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointN = raw;
}

float Fixed::toFloat(void) const
{
	float value = static_cast<float>(fixedPointN) / (1 << fractionalBits);
	return value;
}

int Fixed::toInt(void) const
{
	int value = fixedPointN >> fractionalBits;
	return value;
}

std::ostream& operator<<(std::ostream &os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

bool Fixed::operator>( const Fixed &other) const
{
	bool	toRet;

	toRet = false;
	if (toFloat() > other.toFloat())
		toRet = true;
	return toRet;
}

bool Fixed::operator<(const Fixed &other) const
{
	bool	toRet;

	toRet = false;
	if (toFloat() < other.toFloat())
		toRet = true;
	return toRet;
}

bool Fixed::operator>=(const Fixed &other) const
{
	bool	toRet;

	toRet = false;
	if (toFloat() >= other.toFloat())
		toRet = true;
	return toRet;
}

bool Fixed::operator<=(const Fixed &other) const
{
	bool	toRet;

	toRet = false;
	if (toFloat() <= other.toFloat())
		toRet = true;
	return toRet;
}

bool Fixed::operator==(const Fixed &other) const
{
	bool	toRet;

	toRet = false;
	if (toFloat() == other.toFloat())
		toRet = true;
	return toRet;
}

bool Fixed::operator!=(const Fixed &other) const
{
	bool	toRet;

	toRet = false;
	if (toFloat() != other.toFloat())
		toRet = true;
	return toRet;
}

float Fixed::operator+(const Fixed &other) const
{
	return toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed &other) const
{
	return toFloat() - other.toFloat();
}

float Fixed::operator*(const Fixed &other) const
{
	return toFloat() * other.toFloat();
}

float Fixed::operator/(const Fixed &other) const
{
	return toFloat() / other.toFloat();
}

Fixed&	Fixed::operator++()
{
	fixedPointN += 1;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);

	fixedPointN += 1;
	return temp;
}

Fixed&	Fixed::operator--()
{
	fixedPointN -= 1;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);

	fixedPointN -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 < fixed2)? fixed1 : fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 < fixed2)? fixed1 : fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 > fixed2)? fixed1 : fixed2;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 > fixed2)? fixed1 : fixed2;
}
