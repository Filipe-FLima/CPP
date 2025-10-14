/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:59:02 by flima             #+#    #+#             */
/*   Updated: 2025/09/10 11:16:14 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		Bureaucrat teamLeader("John", 100);
		
		std::cout << teamLeader << std::endl;
		try
		{
			teamLeader.gradeDown();
			std::cout << teamLeader << std::endl;
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	{
		try
		{
			Bureaucrat teamLeader("Thiago", 1);
			std::cout << teamLeader << std::endl;
			teamLeader.gradeUp();
			std::cout << teamLeader << std::endl;
			
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			Bureaucrat teamLeader("Filipe", 150);
			std::cout << teamLeader << std::endl;
			teamLeader.gradeDown();
			std::cout << teamLeader << std::endl;
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}