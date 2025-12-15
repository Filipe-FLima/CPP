/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:49:46 by filipe            #+#    #+#             */
/*   Updated: 2025/12/15 11:40:47 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
	{
		std::cerr << "Error: missing arguments." << std::endl;
		return (1);
	}
    
    intVector v;
    intDeque  d;

    try
    {
        PmergeME::fillContainer(v, d, ++argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    
    {
        PmergeME::SortTime time;
        intVector sorted = PmergeME::PmergeMe(v);
        double _time = time.getTime();

        std::cout << "compCount = " << Pair::compCount << "\n";
        std::cout << "Before: ";
        for (size_t i = 0; i < v.size(); ++i)
        {
            std::cout << v[i] << ' ';
        }
        std::cout << std::endl;
        std::cout << "After: ";
        for (size_t i = 0; i < sorted.size(); ++i)
        {
            std::cout << sorted[i] << ' ';
        }
        std::cout << std::endl;
        std::cout << "Time to process a range of " << v.size() 
			<< " elements with std::vector : " << _time << " us";
    }
    std::cout << std::endl;
    {
        PmergeME::SortTime time;
        intDeque sorted = PmergeME::PmergeMe(d);
        double _time = time.getTime();
        std::cout << "Time to process a range of " << v.size() << 
			" elements with std::deque : " << _time << " us" << std::endl;
    }

    return 0;
}

//implement - no duble numbers,
