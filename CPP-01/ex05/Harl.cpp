/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:45:06 by flima             #+#    #+#             */
/*   Updated: 2025/07/20 19:35:55 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple"
		"-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You did not put enough"
	 " bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout <<  "I think I deserve to have some extra bacon for free. I have been coming for"
		" years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*funcs[])(){
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	std::string levels[] = {"debug", "info", "warning", "error"};
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level){
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "Level not found" <<std::endl;
}
