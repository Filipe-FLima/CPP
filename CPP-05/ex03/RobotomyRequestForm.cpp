/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:27:00 by flima             #+#    #+#             */
/*   Updated: 2025/10/16 21:36:57 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target) :
	AForm("RobotomyRequest", RR_REQUIRETODSIGN, RR_REQUIREDTOEXEC), 
	target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other),
	target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action() const
{
	std::cout << "BZZZZZ.... *drilling noises* " << std::endl;
	
	std::srand(time(NULL));
	if (std::rand() % 2)
		std::cout << getTarget() + " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy on " << getTarget() + " has failed." << std::endl;
}