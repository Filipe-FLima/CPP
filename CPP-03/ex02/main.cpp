/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:29:31 by flima             #+#    #+#             */
/*   Updated: 2025/08/07 20:38:41 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	handleRobotsB(ScavTrap& A, FragTrap& B)
{
	std::string	command;
	
	std::cout << "Give one of the following commands to " << B.getName()
		 << ": ATTACK or REPAIR " << std::endl;
	std::getline(std::cin, command);
	if (command == "ATTACK")
	{
		B.attack(A.getName());
		if (!B.checkEnergy())
			A.takeDamage(B.getAttackDamage());
	}
	else if (command == "REPAIR")
		B.beRepaired(STATS * FRAG_REPAIR);
}

void	handleRobotsA(ScavTrap& A, FragTrap& B)
{
	std::string	command;
	
	std::cout << "Give one of the following commands to " << A.getName()
		 << ": ATTACK or REPAIR " << std::endl;
	std::getline(std::cin, command);
	if (command == "ATTACK")
	{
		A.attack(B.getName());
		if (!A.checkEnergy())
			B.takeDamage(A.getAttackDamage());
	}
	else if (command == "REPAIR")
		A.beRepaired(STATS * REPAIR_SCAV);
}

int	main(void)
{
	ScavTrap A("Clappy");
	FragTrap B("Minion");
	FragTrap C;

	C = B;
	std::string	input;

	while ((A.is_alive() && B.is_alive()))
	{
		std::cout << "\nScavTraps stats\n\n" << std::setw(10) << std::left << "ScavTrap" << "|"
			<< std::setw(10) << std::left << "Hit Points" << "|" << std::setw(10)
			<< std::left << "Damage" << "|" << std::setw(10) << std::left << "Energy" << std::endl
			<< std::setw(10) << std::left << "A" << "|" << std::setw(10) << std::left 
			<< A.getHitPoints() << "|" << std::setw(10) << std::left << A.getAttackDamage() << "|"
			<< std::setw(10) << std::left << A.getEnergyPoints() << std::endl
			<< std::setw(10) << std::left << "B" << "|" << std::setw(10) << std::left 
			<< B.getHitPoints() << "|" << std::setw(10) << std::left << B.getAttackDamage() << "|"
			<< std::setw(10) << std::left << B.getEnergyPoints() << std::endl;
		std::cout << "Pick up a robot (ScavTrap): A or B" << std::endl;
		std::getline(std::cin, input);
		if (input == "A")
			handleRobotsA(A, B);
		else if (input == "B")
			handleRobotsB(A, B);
	}
	if (!A.is_alive() && !B.is_alive())
		std::cout << "\nBoth have been destroyed in battle!\n" << std::endl;
	else if (!A.is_alive())
		std::cout << "\nA has fallen. B is victorious!\n" << std::endl;
	else
		std::cout << "\nB has fallen. A is victorious!\n" << std::endl;
	C.highFivesGuys();
	return 0;
}