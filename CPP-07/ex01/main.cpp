/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:15:49 by filipe            #+#    #+#             */
/*   Updated: 2025/11/02 20:18:18 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

int main()
{
    {
        int arr[5]{1,2,3,4,5};
        
        std::cout << "Normal values: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<int>);
        std::cout << std::endl;
        std::cout << "After increase: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), increase<int>);
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<int>);
        std::cout << std::endl;
        std::cout << "After decrease: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), decrease<int>);
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<int>);
        std::cout << std::endl << std::endl ;
    }

    {
        double arr[5]{1.5,2.3,3.4,4.8,5.0};
        
        std::cout << "Normal values: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<double>);
        std::cout << std::endl;
        std::cout << "After increase: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), increase<double>);
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<double>);
        std::cout << std::endl;
        std::cout << "After decrease: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), decrease<double>);
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<double>);
        std::cout << std::endl << std::endl ;
    }

    {
        char arr[]{'H','e','l','l','o'};
        
        std::cout << "Normal values: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<char>);
        std::cout << std::endl;
        std::cout << "After increase: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), increase<char>);
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<char>);
        std::cout << std::endl;
        std::cout << "After decrease: ";
        iter(arr, sizeof(arr) / sizeof(arr[0]), decrease<char>);
        iter(arr, sizeof(arr) / sizeof(arr[0]), printContent<char>);
        std::cout << std::endl << std::endl ;
    }

    {
        const std::string array[]{"Hello", "What's up", "world"};
        iter(array, sizeof(array) / sizeof(array[0]), printContent<std::string>);
        std::cout << std::endl << std::endl ;
    }

    return 0;
}