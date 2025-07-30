/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:02:08 by flima             #+#    #+#             */
/*   Updated: 2025/07/28 12:41:38 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedPointN;
		static const int fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const int &value);
		Fixed(const float &value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		float	operator+(const Fixed& other) const;
		float	operator-(const Fixed& other) const;
		float	operator*(const Fixed& other) const;
		float	operator/(const Fixed& other) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		static Fixed& 			min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& 	min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& 			max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& 	max(const Fixed& fixed1, const Fixed& fixed2);
		
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif