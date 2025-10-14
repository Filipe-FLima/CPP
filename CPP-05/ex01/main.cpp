/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:59:02 by flima             #+#    #+#             */
/*   Updated: 2025/10/14 20:07:42 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		try
		{
			Bureaucrat teamLeader("John", 150);
			std::cout << teamLeader << std::endl;
			Form F1("Tax Form", 150, 50);
			std::cout << F1 << std::endl;
			teamLeader.signForm(F1);
			std::cout << F1 << std::endl;
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
			Bureaucrat teamLeader("Thiago", 150);
			std::cout << teamLeader << std::endl;
			Form F1("Tax Form", 50, 50);
			std::cout << F1 << std::endl;
			teamLeader.signForm(F1);
			std::cout << F1 << std::endl;
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
			Bureaucrat teamLeader("Marcos", 150);
			std::cout << teamLeader << std::endl;
			Form F1("Tax Form", 0, 50); //grade to sign higher than required
			std::cout << F1 << std::endl;
			teamLeader.signForm(F1);
			std::cout << F1 << std::endl;
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
			Bureaucrat teamLeader("Marcos", 150);
			std::cout << teamLeader << std::endl;
			Form F1("Tax Form", 10, 151); //grade to execute lower than required
			std::cout << F1 << std::endl;
			teamLeader.signForm(F1);
			std::cout << F1 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}