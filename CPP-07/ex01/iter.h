/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:57:50 by filipe            #+#    #+#             */
/*   Updated: 2025/11/02 20:18:27 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void    printContent(const T content)
{
    std::cout << content << " ";
}

template <typename T>
void    increase(T& N)
{
    N++;
}

template <typename T>
void    decrease(T& N)
{
    N--;
}


template <typename T, typename Func>

void    iter(T* array, const size_t len, Func func)
{
    for (size_t i = 0; i < len; i++)
    {
        func(array[i]);
    }
}


#endif