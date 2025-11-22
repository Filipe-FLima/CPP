/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:12:40 by filipe            #+#    #+#             */
/*   Updated: 2025/11/19 15:16:18 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static std::string trim(std::string& s) 
{
    size_t first = s.find_first_not_of(' ');
    size_t last = s.find_last_not_of(' ');
    
    return s.substr(first, last - first + 1);
}

static bool     isValidOperator(char c)
{
    if (c != ' ' && c != '*' && c != '/' && c != '-' && c != '+')
        return false;
    return true;
}

static bool    isValidInput(std::string s)
{
    s = trim(s);
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit(s[i]) && !isValidOperator(s[i]))
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std:: cerr << "Error: Invalid input.\n";
        return 1;
    }
    if (!isValidInput(argv[1]))
    {
        std:: cerr << "Error: bad Polish mathematical expression.\n";
        return 1;   
    }
    
    try
    {
       RPN(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
    
}