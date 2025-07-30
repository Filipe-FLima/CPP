/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:06:40 by flima             #+#    #+#             */
/*   Updated: 2025/07/30 11:31:51 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	A(0.0f, 0.0f);
	Point	B(5.0f, 0.0f);
	Point	C(0.0f, 5.0f);
	Point	P1(2.0f, 0.0f);

	bool isIside = bsp(A, B, C, P1);
	if (isIside)
		std::cout << "P1 is inside the triangle" << std::endl;
	else
		std::cout << "P1 is not inside the triangle" << std::endl;
	return 0;
}