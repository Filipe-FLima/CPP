/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:03:33 by flima             #+#    #+#             */
/*   Updated: 2025/11/07 11:11:33 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"

int main()
{
    {
		try
		{
			std::cout << "\nC-style array of int..." << std::endl;
			int array[]{1, 78, 45, 66, 2};
			auto it(easyfind(array, 78));
			auto index{std::distance(std::begin(array), it)};
			std::cout << *it << " has been found at index " << index << "\n" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << " Element not found!" << "\n" << std::endl;
		}
	}
	{
		try
		{
			std::cout << "Vector container of int..." << std::endl;
			std::vector<int> array{1, 78, 45, 66, 2};
			auto it(easyfind(array, 2));
			auto index{std::distance(std::begin(array), it)};
			std::cout << *it << " has been found at index " << index << "\n" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << " Element not found!" << "\n" << std::endl;
		}
	}
	{
		try
		{
			std::cout << "Deque container of int..." << std::endl;
			std::deque<int> array{1, 78, 45, 66, 2};
			auto it(easyfind(array, 45));
			auto index{std::distance(std::begin(array), it)};
			std::cout << *it << " has been found at index " << index << "\n" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << " Element not found!" << "\n" << std::endl;
		}
	}
	{
		try
		{
			std::cout << "Array container of int..." << std::endl;
			std::array<int, 8> array{1, 78, 45, 66, 2, 69, 0, 33};
			auto it(easyfind(array, 33));
			auto index{std::distance(std::begin(array), it)};
			std::cout << *it << " has been found at index " << index << "\n" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << " Element not found!" << "\n" << std::endl;
		}
	}
	{
		try
		{
			std::cout << "List container of int..." << std::endl;
			std::list<int> array{1, 78, 45, 66, 2, 69, 0, 33};
			auto it(easyfind(array, 33));
			auto index{std::distance(std::begin(array), it)};
			std::cout << *it << " has been found at position " << index << "\n" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << " Element not found!" << "\n" << std::endl;
		}
	}
	{
		try
		{
			std::cout << "List container of int..." << std::endl;
			std::list<int> array{1, 78, 45, 66, 2, 69, 0, 33};
			auto it(easyfind(array, 11));
			auto index{std::distance(std::begin(array), it)};
			std::cout << *it << " has been found at position " << index << "\n" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Element not found!" << "\n" << std::endl;
		}
	}

    return 0;
}