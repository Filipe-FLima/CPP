/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:22:03 by flima             #+#    #+#             */
/*   Updated: 2025/07/20 19:31:28 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string	getValidInput(std::string prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
		if (!input.empty())
			return input;
		std::cout << "Error: empty input!" << std::endl;
	}
}

int main(void)
{
	Harl	harl;
	std::string level;

	while (true)
	{
		level = getValidInput("Type a complaint's level: debug, info, warning, error or  EXIT if Harl is satisfied");
		if (level == "EXIT")
			break;
		harl.complain(level);		
	}
	return 0;
}