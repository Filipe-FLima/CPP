/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:41:16 by flima             #+#    #+#             */
/*   Updated: 2025/11/10 15:18:57 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <array>
#include <list>


template <typename T>
auto easyFind(T& container, int tofind);

#include "easyfind.tpp"

#endif

