/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:32:39 by filipe            #+#    #+#             */
/*   Updated: 2025/11/07 14:59:51 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"


int main() 
{
	{
		try
		{
			Span v(3);

			v.printElements();
			std::cout << std::endl;
			v.addNumber(78);
			// v.addNumber(21);
			// v.addNumber(21);
			// v.addNumber(21);
			v.printElements();
			std::cout << std::endl;
			v.addRange(v.end() + 1, v.end()); //reformular essa logica 
			v.printElements();
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	
	return 0;   
}
