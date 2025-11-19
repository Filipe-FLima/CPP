/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:38:27 by filipe            #+#    #+#             */
/*   Updated: 2025/11/19 15:35:33 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int add(std::stack<int> &tokens)
{
    int b = tokens.top();
    tokens.pop();
    int a = tokens.top();
    
    return  a + b;
}

static int subtract(std::stack<int> &tokens)
{
    return  a - b;
}

static int multiply(std::stack<int> &tokens)
{
    return  a * b;
}

static int divide(std::stack<int> &tokens)
{
    return  a / b;
}

static int convertTokenNum(std::string& n)
{
    int _n;

    try 
    {
        _n = std::stoi(n);
    }
    catch (std::exception& e)
    {
        throw std::runtime_error("Error: impossible number convertion.");
    }
    if (_n > 9)
        throw std::runtime_error("Error: Number greater/equal than 10.");
}
int     getOperator(char c)
{
    std::string cases("+-/*");

    for (int i = 0; i < cases.size(); ++i)
    {
        if (cases[i] == c)
            return i; 
    }
    return -1;
}

void    operations(std::stack<int>& tokens, std::string& _operator)
{
    if (_operator.size() != 1)
        throw std::runtime_error("Error: band operator sign.");
    
    int _case = _operator[0];
    
    switch (_case)
    {
    case ADD:
        /* code */
        break;
    
    default:
        break;
    }
}

void    RPN(std::string PMathEx)
{
    std::istringstream      input(PMathEx);
    std::string             token;
    std::stack<int>         tokensNum;

    while (input >> token)
    {
        if (token.find_first_of("+-/*") == std::string::npos)
        {
            try
            {
                tokensNum.push(convertTokenNum(token));
            }
            catch(const std::exception& e)
            {
                throw (e.what());
            }
            continue;
        }
        
    }
    
}