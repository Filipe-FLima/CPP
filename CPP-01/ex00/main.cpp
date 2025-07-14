/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:54:51 by flima             #+#    #+#             */
/*   Updated: 2025/07/14 12:57:45 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	z;
	std::string type;
	std::string name;
	std::string	kill;
	
	while(true)
	{
		std::cout << "Pick your zombie type: randomChump, newZombie or EXIT" << std::endl;
		std::getline(std::cin, type);
		if (type == "randomChump")
		{
			while (true)
			{
				std::cout << "Choose a nice Chump's name" << std::endl;
				std::getline(std::cin, name);
				if (name.empty())
					continue;
				else
				{
					randomChump(name);
					break;
				}
			}
			
		}
		else if (type == "newZombie")
		{
			while (true)
			{
				std::cout << "Choose a nice Zombie's name" << std::endl;
				std::getline(std::cin, name);
				if (name.empty())
					continue;
				else
				{
					z = newZombie(name);
					z->announce();
					while (true)
					{
						std::cout << "Now kill it!!" << std::endl;
						std::getline(std::cin, kill);
						if (kill != "kill")
							continue;
						else
						{
							delete z;
							break;
						}
					}
				}
				break;
			}
		}
		else if (type == "EXIT")
			break;
	}
	return 0;
}

// break main in a readable code