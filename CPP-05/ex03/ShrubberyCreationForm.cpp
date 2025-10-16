/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:27:05 by flima             #+#    #+#             */
/*   Updated: 2025/10/16 20:09:43 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target) :
	AForm("ShrubberyCreation", SC_REQUIRETODSIGN, SC_REQUIREDTOEXEC), 
	target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other),
	target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::action() const
{
	std::ofstream file(getTarget() + "_shrubbery");
	if(file.is_open())
	{
		file << "       _-_\n"
				"    /~~   ~~\\\n"
				" /~~         ~~\\\n"
				"{               }\n"
				" \\  _-     -_  /\n"
				"   ~  \\\\ //  ~\n"
				"_- -   | | _- _\n"
				"  _ -  | |   -_\n"
				"      // \\\\\n";
		file.close();
	}
	else
	{
		std::cerr << "Error: Could not open file " << getTarget() + "_shrubbery" << std::endl;
	}
}