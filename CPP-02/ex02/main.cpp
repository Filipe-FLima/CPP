/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:06:40 by flima             #+#    #+#             */
/*   Updated: 2025/07/28 12:56:17 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;

	// if (a != b)
	// 	std::cout << "b is equal\n";
	// else
	// 	std::cout << "a is no\n";

	// std::cout << "a + b = " << a + b << std::endl;
	// std::cout << "a - b = " << a - b << std::endl;
	// std::cout << "a * b = " << a * b << std::endl;
	// std::cout << "a / b = " << a / b << std::endl;
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}