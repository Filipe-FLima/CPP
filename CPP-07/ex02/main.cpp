/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:44:15 by filipe            #+#    #+#             */
/*   Updated: 2025/11/02 19:33:46 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"


int main()
{
    {
        Array<int> a;
        try 
        {
            std::cout << a[0] << std::endl;
            a[0] = 1;
            std::cout << a[0] << std::endl;
            a[0] = 42;
            std::cout << a[0] << std::endl;
            std::cout << "Array size: " << a.getSize() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Accessing element out of bounds" << std::endl;
        }
    
    }
    std::cout << std::endl;
        {
        Array<int> const a(2);
        try 
        {
            // a[0] = 42;
            std::cout << a[0] << std::endl;
            std::cout << a[1] << std::endl;
            std::cout << "Array size: " << a.getSize() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Accessing element out of bounds" << std::endl;
        }
    
    }
    std::cout << std::endl;
    {
        Array<std::string> a;
        try 
        {
            a[0] = "hello";
            std::cout << a[0] << std::endl;
            std::cout << "Array size: " << a.getSize() << std::endl;
            a[1] = "World";
            std::cout << a[0] << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Accessing element out of bounds" << std::endl;
        }
    
    }
    std::cout << std::endl;
        {
        Array<std::string> a(5);
        try 
        {
            a[0] = "hello ";
            std::cout << a[0] << std::endl;
            std::cout << "Array size: " << a.getSize() << std::endl;
            a[1] = "World ";
            a[2] = "what's up?";
            std::cout << a[0] << a[1] << a[2] << a[3] << a[4] << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Accessing element out of bounds" << std::endl;
        }
    
    }
    std::cout << std::endl;
    {
        std::cout << "Copy constructor...\n";
        
        Array<std::string> a(5);
        Array<std::string> b = a;
        try 
        {
            std::cout << "a[0]: " << a[0] << std::endl;
            std::cout << "b[0]: " << b[0] << std::endl;
            a[0] = "42";
            b[0] = "World";
            std::cout << "a[0]: " << a[0][0] << a[0][1]<< std::endl;
            std::cout << "b[0]: " << b[0] << std::endl;
            std::cout << "Array a size: " << a.getSize() << std::endl;
            std::cout << "Array b size: " << b.getSize() << std::endl;
            
        }
        catch (const std::exception& e)
        {
            std::cerr << "Accessing element out of bounds" << std::endl;
        }
    
    }
    std::cout << std::endl;
    {
        std::cout << "Copy assignment constructor...\n";
        
        Array<std::string> a(5);
        Array<std::string> b;
        try 
        {
            a[0] = "Hello";
            b = a;
            std::cout << "a[0]: " << a[0] << std::endl;
            std::cout << "b[0]: " << b[0] << std::endl;
            a[0] = "42";
            b[0] = "World";
            std::cout << "a[0]: " << a[0] << std::endl;
            std::cout << "b[0]: " << b[0] << std::endl;
            std::cout << "Array a size: " << a.getSize() << std::endl;
            std::cout << "Array b size: " << b.getSize() << std::endl;
            
        }
        catch (const std::exception& e)
        {
            std::cerr << "Accessing element out of bounds" << std::endl;
        }
    
    }
    std::cout << std::endl;
    return 0;
}