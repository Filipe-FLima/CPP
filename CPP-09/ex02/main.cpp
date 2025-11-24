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
        std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;
        std::cout << d[0] << " " << d[1] << " " << d[2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
    return 0;
}