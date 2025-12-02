/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:49:46 by filipe            #+#    #+#             */
/*   Updated: 2025/11/24 11:58:38 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"


int main(int argc, char **argv)
{
    (void)argc;
    
    intVector v;
    intDeque  d;

    try
    {
        PmergeME::fillContainer(v, d, ++argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    (void)d;
    
    intVector sorted = PmergeME::sort(v);

    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < sorted.size(); ++i)
    {
        std::cout << sorted[i] << ' ';
    }
    std::cout << std::endl;
    
    return 0;
}