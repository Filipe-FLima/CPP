#include "Intern.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:33:15 by filipe            #+#    #+#             */
/*   Updated: 2025/10/16 20:33:16 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

int	getCaseIndex(const std::string &formName)
{
	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
			return i;
	}
	return -1;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	
	int caseIndex = getCaseIndex(formName);
	switch (caseIndex)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		case -1:
			break;
	}
	return nullptr;
}

const char *Intern::FormNotFoundException::what() const noexcept
{
	return "Intern could not find the requested form.";
}
