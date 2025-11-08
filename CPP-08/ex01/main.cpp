/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:32:39 by filipe            #+#    #+#             */
/*   Updated: 2025/11/08 14:05:44 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"


int main() 
{
	{
		try
		{
			Span v(5);
			
			std::cout << "Adding one element and filling the rest using a range of iterators..." << std::endl;
			v.printElements();
			std::cout << std::endl;
			v.addNumber(78);
			v.printElements();
			std::cout << std::endl;
			v.addRange(v.begin() + v.getFilledIdx(), v.end());
			v.printElements();
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << "==========================================" << std::endl;
	{
		try
		{
			Span v(3);
			
			std::cout << "Using a invalid iterator..." << std::endl;
			v.printElements();
			std::cout << std::endl;
			v.addNumber(78);
			v.printElements();
			std::cout << std::endl;
			v.addRange(v.begin() + 3, v.end());
			v.printElements();
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << "==========================================" << std::endl;
	{
		try
		{
			Span v(3);

			std::cout << "Trying to add more element than can be stored..." << std::endl;
			v.printElements();
			std::cout << std::endl;
			v.addNumber(78);
			v.addNumber(77);
			v.addNumber(23);
			v.addNumber(78); // catch here 4 element
			v.printElements();
			std::cout << std::endl;
			v.addRange(v.begin() + v.getFilledIdx(), v.end());
			v.printElements();
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << "==========================================" << std::endl;
	{
		try
		{
			Span v(10);
			
			std::cout << "Trying to get the span but there is just one element..." << std::endl;
			v.printElements();
			std::cout << std::endl;
			v.addNumber(78);
			// v.addNumber(50);
			v.printElements();
			std::cout << std::endl;
			std::cout << v.longestSpan() << std::endl; //catch error: only one element/ no span possible
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << "==========================================" << std::endl;
	{
		try
		{
			std::cout << "Using main from subject" << std::endl;
			Span v(5);

			v.printElements();
			std::cout << std::endl;
			v.addNumber(6);
			v.addNumber(3);
			v.addNumber(17);
			v.addNumber(9);
			v.addNumber(11);
			v.printElements();
			std::cout << "\nThe sortest span is " << v.shortestSpan() << std::endl;
			std::cout << "The longest span is " << v.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << "==========================================" << std::endl;
	{
		try
		{
			Span v(10000000);

			std::cout << "\n Using range of iterators to fill all (10.000.000) elements..." << std::endl;
			v.addRange(v.begin() + v.getFilledIdx(), v.end());
			v.printElements();
			std::cout << "\n\nThe sortest span is " << v.shortestSpan() << std::endl;
			std::cout << "The longest span is " << v.longestSpan() << std::endl;
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;   
}
