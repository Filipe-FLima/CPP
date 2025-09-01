/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:59:02 by flima             #+#    #+#             */
/*   Updated: 2025/09/01 16:27:54 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int	main()
{
	//do a default constructor
	Bureaucrat teamLeader("John", 1);
	
	std::cout << teamLeader << std::endl;
	try
	{
		teamLeader.gradeUp();
		std::cout << teamLeader << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}