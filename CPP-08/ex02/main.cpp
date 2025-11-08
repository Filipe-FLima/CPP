/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:18:55 by flima             #+#    #+#             */
/*   Updated: 2025/11/08 19:54:37 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.h"
#include <stack>
#include <list>

int main()
{
	{
		try
		{
			MutantStack<int> mstack;
			
			mstack.push(5);
			mstack.push(17);
			
			std::cout << mstack.top() << std::endl;
			
			mstack.pop();
			
			std::cout << mstack.size() << std::endl;
			
			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			//[...]
			mstack.push(0);
			
			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
			
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			std::cout << "Using list container...\n";
			std::list<int> mstack;
			
			mstack.push_back(5);
			mstack.push_back(17);
			
			std::cout << mstack.back() << std::endl;
			
			mstack.pop_back();
			
			std::cout << mstack.size() << std::endl;
			
			mstack.push_back(3);
			mstack.push_back(5);
			mstack.push_back(737);
			//[...]
			mstack.push_back(0);
			
			std::list<int>::iterator it = mstack.begin();
			std::list<int>::iterator ite = mstack.end();
			
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			MutantStack<int> mstack;
			MutantStack<int> mstackT;
			
			mstack.push(5);
			mstack.push(17);
			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			mstack.push(0);
			
			std::cout << "mstack size " << mstack.size() << std::endl;
			std::cout << "mstackT size " << mstackT.size() << std::endl;
			
			std::cout << "\nSwaping stacks" << std::endl;
			mstack.swap(mstackT);
			MutantStack<int>::iterator it = mstackT.begin();
			MutantStack<int>::iterator ite = mstackT.end();
			
			std::cout << "mstack size " << mstack.size() << std::endl;
			std::cout << "mstackT size " << mstackT.size() << std::endl;
			
			++it;
			--it;
			while (it != ite)
			{
				*it += 100;
				std::cout << *it << std::endl;
				++it;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}
	std::cout << std::endl;
	{
		try
		{
			MutantStack<int> mstack;
		
			mstack.push(5);
			mstack.push(17);
			std::cout << mstack.top() << std::endl;
			mstack.pop();
			std::cout << mstack.top() << std::endl;
			std::cout << ((mstack.empty())? "true" : "false") << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	// std::stack<int> s(mstack);
	return 0;
}