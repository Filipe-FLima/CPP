/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:59:02 by flima             #+#    #+#             */
/*   Updated: 2025/10/16 20:23:32 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	{
		try
		{
			Bureaucrat teamLeader("John", 6);
			std::cout << teamLeader << std::endl;
			PresidentialPardonForm F1("Thomas");
			std::cout << F1 << std::endl;
			teamLeader.signForm(F1);
			std::cout << F1 << std::endl;
			teamLeader.executeForm(F1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		
	}

	std::cout << std::endl;
	
	{
		try
		{
			Bureaucrat teamLeader("Thiago", 45);
			std::cout << teamLeader << std::endl;
			RobotomyRequestForm F1("V");
			std::cout << F1 << std::endl;
			teamLeader.signForm(F1);
			std::cout << F1 << std::endl;
			teamLeader.executeForm(F1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << std::endl;
	
	{
		try
		{
			Bureaucrat teamLeader("Marcos", 1);
			std::cout << teamLeader << std::endl;
			ShrubberyCreationForm F1("school");
			std::cout << F1 << std::endl;
			teamLeader.signForm(F1);
			std::cout << F1 << std::endl;
			teamLeader.executeForm(F1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

}