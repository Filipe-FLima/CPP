/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:41:39 by flima             #+#    #+#             */
/*   Updated: 2025/07/18 11:12:28 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	getValidInput(std::string prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
		if (!input.empty())
			return input;
	}
}

int	getHordeSize(void)
{
	while (true)
	{	
		std::string input = getValidInput("Choose your horda's size!");
		try
		{
			std::string::size_type sz;
			int hordeSize = std::stoi(input, &sz);
			if (sz != input.size() && !std::isdigit(input[sz])){
				std::cerr << "Please enter only numbers." << std::endl;
				continue;
			}
			if (hordeSize <= 0){
				std::cerr << "Come on, at least one zombie to have fun!! Horde out of range!" << std::endl;
				continue;
			}
			else
				return hordeSize;
		}
		catch(const std::out_of_range& e){
			std::cerr << "Do you want to cause an apocalypse? Horde size out of range!!" << std::endl;
		}
		catch(const std::invalid_argument& e){
			std::cerr << "Please enter only numbers." << std::endl;
		}
	}
}
int	main(void)
{
	Zombie* horde;
	std::string name;
	int			hordeSize;
	
	name = getValidInput("Pick a zombie name!");
	hordeSize = getHordeSize();
	horde = zombieHorde(hordeSize, name);
	for (int i = 0; i < hordeSize; i++){
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}