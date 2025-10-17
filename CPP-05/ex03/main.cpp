/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:59:02 by flima             #+#    #+#             */
/*   Updated: 2025/10/17 18:07:59 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << std::endl;
	{
		Bureaucrat teamLeader("Filipe", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "home");
		try
		{
			if (!rrf)
				throw Intern::FormNotFoundException();
			rrf->beSigned(teamLeader);
			rrf->execute(teamLeader);
			std::cout << teamLeader.getName() << " signed and executed " <<
			 rrf->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete rrf;
	}

	std::cout << std::endl;
	
	{
		Bureaucrat teamLeader("Thiago", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Arthur");
		try
		{
			if (!rrf)
				throw Intern::FormNotFoundException();
			rrf->beSigned(teamLeader);
			rrf->execute(teamLeader);
			std::cout << teamLeader.getName() << " signed and executed " <<
			 rrf->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete rrf;
		
	}

	std::cout << std::endl;
	
	{
		Bureaucrat teamLeader("Marcos", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		try
		{
			if (!rrf)
				throw Intern::FormNotFoundException();
			rrf->beSigned(teamLeader);
			rrf->execute(teamLeader);
			std::cout << teamLeader.getName() << " signed and executed " <<
			 rrf->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete rrf;
	}

	std::cout << std::endl;
	
	{
		Bureaucrat teamLeader("Marcos", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("randomName", "Bender");
		try
		{
			if (!rrf)
				throw Intern::FormNotFoundException();
			rrf->beSigned(teamLeader);
			rrf->execute(teamLeader);
			std::cout << teamLeader.getName() << " signed and executed " <<
			 rrf->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete rrf;
	}
	std::cout << std::endl;
	return 0;
}