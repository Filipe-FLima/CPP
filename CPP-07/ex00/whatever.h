/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:02:07 by filipe            #+#    #+#             */
/*   Updated: 2025/11/02 20:03:40 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>
#include <string>


template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	
	a = b;
	b = temp;
}

template <typename T>
T min(T& a, T& b)
{
	return (a < b) ? a : b;
}

template <typename T>
T max(T& a, T& b)
{
	return (a > b) ? a : b;
}

#endif