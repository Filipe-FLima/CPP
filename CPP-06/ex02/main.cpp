/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:07:49 by flima             #+#    #+#             */
/*   Updated: 2025/10/27 13:19:09 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>
#include <ctime>

Base* 	generate(void)
{
	int obj = rand() % 3;

	switch (obj)
	{
		
		case 0:
			std::cout << "An instance of A was created." << std::endl;
			return new A();
		case 1:
			std::cout << "An instance of B was created." << std::endl;
			return new B();
		default:
			std::cout << "An instance of C was created." << std::endl;
			return new C();
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class type C" << std::endl;
	else
		std::cout << "Could not identify the class type." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Class type A" << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "Class type B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "Class type C" << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << "Could not identify the class type." << std::endl;
			}
		}
		
	}
}

int main()
{
	std::srand(std::time(nullptr));
	{
		Base* p = generate();
		std::cout << "Using a pointer to identify the class type." << std::endl;
		identify(p);
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Using a reference to identify the class type." << std::endl;
		identify(*p);
		std::cout << std::endl;
		delete p;
	}

	{
		Base* p = generate();
		std::cout << "Using a pointer to identify the class type." << std::endl;
		identify(p);
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Using a reference to identify the class type." << std::endl;
		identify(*p);
		std::cout << std::endl;
		delete p;
	}

	{
		Base* p = generate();
		std::cout << "Using a pointer to identify the class type." << std::endl;
		identify(p);
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Using a reference to identify the class type." << std::endl;
		identify(*p);
		std::cout << std::endl;
		delete p;
	}

	{
		Base* p = NULL;
		std::cout << "Using a pointer to identify the class type." << std::endl;
		identify(p);
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Using a reference to identify the class type." << std::endl;
		identify(*p);
		std::cout << std::endl;
		delete p;
	}

	return 0;

}