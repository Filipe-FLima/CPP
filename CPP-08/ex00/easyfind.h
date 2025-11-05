/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:41:16 by flima             #+#    #+#             */
/*   Updated: 2025/11/05 13:30:05 by flima            ###   ########.fr       */
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
auto easyfind(T& container, int tofind);

#include "easyfind.tpp"

#endif

