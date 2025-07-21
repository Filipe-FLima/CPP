/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:45:06 by flima             #+#    #+#             */
/*   Updated: 2025/07/21 17:09:25 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my 7XL-double-cheese-triple"
		"-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money. You did not put enough"
	 " bacon in my burger! If you did, I would not be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free. I have been coming for"
		" years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(Levels level)
{
	switch (level)
	{
	case MOANER:
		std::cout << "[ Probably complaining about insignificant problems ]" <<std::endl;
		break;
	case DEBUG:
		debug();
		[[fallthrough]];
	case INFO:
		info();
		[[fallthrough]];
	case WARNING:
		warning();
		[[fallthrough]];
	case ERROR:
		error();
		break;
	}
}

