/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:09:24 by filipe            #+#    #+#             */
/*   Updated: 2025/11/19 15:33:24 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

enum operators
{
    ADD,
    SUB,
    DIV,
    MULT
};

void    RPN(std::string PMathEx);

#endif