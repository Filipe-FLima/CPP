/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:54:51 by flima             #+#    #+#             */
/*   Updated: 2025/07/19 18:17:57 by flima            ###   ########.fr       */
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

void	getRandomChump(void)
{
	std::string	name = getValidInput("Choose a nice Chump's name");
	randomChump(name);
}

void	getNewZombie(void)
{
	Zombie*	z;
	std::string	kill;
	
	std::string	name = getValidInput("Choose a nice Zombie's name");
	z = newZombie(name);
	z->announce();
	while (true)
	{
		std::cout << "Now kill it!! (type 'kill')" << std::endl;
		std::getline(std::cin, kill);
		if (kill == "kill")
		{
			delete z;
			break;
		}
	}
}

int	main(void)
{
	std::string type;
	
	while(true)
	{
		std::cout << "Create your zombie type: randomChump, newZombie or EXIT" << std::endl;
		std::getline(std::cin, type);
		if (type == "randomChump")
			getRandomChump();
		else if (type == "newZombie")
			getNewZombie();
		else if (type == "EXIT")
			break;
		else
			std::cout << "Invalid command. Try again." << std::endl;
	}
	return 0;
}
