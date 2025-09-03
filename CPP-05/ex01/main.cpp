/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:59:02 by flima             #+#    #+#             */
/*   Updated: 2025/09/03 20:20:18 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		Bureaucrat teamLeader("John", 150);
		
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
			Bureaucrat teamLeader("Thiago", 0);
			std::cout << teamLeader << std::endl;
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
			Bureaucrat teamLeader("Filipe", 50);
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