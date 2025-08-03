/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:29:31 by flima             #+#    #+#             */
/*   Updated: 2025/08/03 15:46:36 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	handleClapB(ClapTrap& A, ClapTrap& B)
{
	std::string	command;
	
	std::cout << "Give one of the following commands to " << A.getName()
		 << ": ATTACK or REPAIR " << std::endl;
	std::getline(std::cin, command);
	if (command == "ATTACK")
	{
		B.attack(A.getName());
		if (!B.checkEnergy())
			A.takeDamage(B.getAttackDamage());
	}
	else if (command == "REPAIR")
		B.beRepaired(STATS * 0.1);
}

void	handleClapA(ClapTrap& A, ClapTrap& B)
{
	std::string	command;
	
	std::cout << "Give one of the following commands to " << B.getName()
		 << ": ATTACK or REPAIR " << std::endl;
	std::getline(std::cin, command);
	if (command == "ATTACK")
	{
		A.attack(B.getName());
		if (!A.checkEnergy())
			B.takeDamage(A.getAttackDamage());
	}
	else if (command == "REPAIR")
		A.beRepaired(STATS * 0.1);
}

int	main(void)
{
	ClapTrap A("Clappy");
	ClapTrap B("Minion");
	std::string	name;

	while ((A.is_alive() && B.is_alive()))
	{
		std::cout << "\nClapTraps stats\n\n" << std::setw(10) << std::left << "ClapTrap" << "|"
			<< std::setw(10) << std::left << "Hit Points" << "|" << std::setw(10)
			<< std::left << "Damage" << "|" << std::setw(10) << std::left << "Energy" << std::endl
			<< std::setw(10) << std::left << "A" << "|" << std::setw(10) << std::left 
			<< A.getHitPoints() << "|" << std::setw(10) << std::left << A.getAttackDamage() << "|"
			<< std::setw(10) << std::left << A.getEnergyPoints() << std::endl
			<< std::setw(10) << std::left << "B" << "|" << std::setw(10) << std::left 
			<< B.getHitPoints() << "|" << std::setw(10) << std::left << B.getAttackDamage() << "|"
			<< std::setw(10) << std::left << B.getEnergyPoints() << std::endl;
		std::cout << "Pick up a ClapTrap: A or B" << std::endl;
		std::getline(std::cin, name);
		if (name == "A")
			handleClapA(A, B);
		else if (name == "B")
			handleClapB(A, B);
	}
	if (!A.is_alive() && !B.is_alive())
		std::cout << "\nBoth ClapTraps have been destroyed in battle!\n" << std::endl;
	else if (!A.is_alive())
		std::cout << "\nClapTrap A has fallen. ClapTrap B is victorious!\n" << std::endl;
	else
		std::cout << "\nClapTrap B has fallen. ClapTrap A is victorious!\n" << std::endl;
	return 0;
}