/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:59:02 by flima             #+#    #+#             */
/*   Updated: 2025/10/16 21:38:50 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		try
		{
			Bureaucrat teamLeader("Filipe", 150);
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("shrubbery creation", "home");
			rrf->beSigned(teamLeader);
			rrf->execute(teamLeader);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	// std::cout << std::endl;
	
	// {
	// 	try
	// 	{
	// 		Bureaucrat teamLeader("Thiago", 1);
	// 		Intern someRandomIntern;
	// 		AForm* rrf;
	// 		rrf = someRandomIntern.makeForm("presidential pardon", "Arthur");
	// 		rrf->beSigned(teamLeader);
	// 		rrf->execute(teamLeader);
	// 		delete rrf;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
		
	// }

	// std::cout << std::endl;
	
	// {
	// 	try
	// 	{
	// 		Bureaucrat teamLeader("Marcos", 1);
	// 		Intern someRandomIntern;
	// 		AForm* rrf;
	// 		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	// 		rrf->beSigned(teamLeader);
	// 		rrf->execute(teamLeader);
	// 		delete rrf;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }

}