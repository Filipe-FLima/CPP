/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:22:03 by flima             #+#    #+#             */
/*   Updated: 2025/07/21 15:33:00 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Levels	getLevel(std::string level)
{
	if (level == "DEBUG") return DEBUG;
	else if (level == "INFO") return INFO;
	else if (level == "WARNING") return WARNING;
	else if (level == "ERROR") return ERROR;
	else return MOANER;
}

int main(int argc, char** argv)
{
	Harl	harl;
	Levels	levelN;
	std::string level;
	
	if (argc == 2){
		level = argv[1];
		levelN = getLevel(level);
		harl.complain(levelN);
	}
	else if (argc == 1)
		std::cout << "No complaints??" << std::endl;
	else
		std::cout << "[ Harl is complaining a lot about insignificant problems ]" << std::endl;
	return 0;
}