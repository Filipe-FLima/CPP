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

static int top_n_pop(std::stack<int>& tokens)
{
    int value = tokens.top();
    tokens.pop();
    return value;
}

static int add(std::stack<int> &tokens)
{
    int b = top_n_pop(tokens);
    int a = top_n_pop(tokens);
    
    return  a + b;
}

static int subtract(std::stack<int> &tokens)
{
    int b = top_n_pop(tokens);
    int a = top_n_pop(tokens);
    
    return  a - b;
}

static int multiply(std::stack<int> &tokens)
{
    int b = top_n_pop(tokens);
    int a = top_n_pop(tokens);
    
    return  a * b;
}

static int divide(std::stack<int> &tokens)
{
    int b = top_n_pop(tokens);
    int a = top_n_pop(tokens);
    
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
    return _n;
}

static int     getOperator(char c)
{
    std::string cases("+-/*");

    for (size_t i = 0; i < cases.size(); ++i)
    {
        if (cases[i] == c)
            return i; 
    }
    return -1;
}

static void   operations(std::stack<int>& tokens, std::string& _operator)
{
    if (_operator.size() != 1)
        throw std::runtime_error("Error: band operator sign.");
    if (tokens.size() == 2)
        throw std::runtime_error("Error: bad Polish mathematical expression.");
    int _case = getOperator(_operator[0]);
    if (_case == -1)
        throw std::runtime_error("Error: band operator sign.");
    switch (_case)
    {
    case ADD:
        tokens.push(add(tokens));
        break;
    case SUB:
        tokens.push(subtract(tokens));
        break;
    case DIV:
        tokens.push(divide(tokens));
        break;
    case MULT:
        tokens.push(multiply(tokens));
        break;
    }
}

void    RPN(std::string PMathEx)
{
    std::istringstream      input(PMathEx);
    std::string             token;
    std::stack<int>         tokens;

    while (input >> token)
    {
        if (token.find_first_of("+-/*") == std::string::npos)
        {
            try
            {
                tokens.push(convertTokenNum(token));
            }
            catch(const std::exception& e)
            {
                throw (e.what());
            }
            continue;
        }
        else
        {
             try
            {
                operations(tokens, token);
            }
            catch(const std::exception& e)
            {
                throw (e.what());
            }
        }
        
    }

    if (tokens.size() != 1)
        throw std::runtime_error("Error: bad Polish mathematical expression.");
    std::cout << tokens.top() << std::endl;
}