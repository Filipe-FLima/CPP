/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:53:00 by flima             #+#    #+#             */
/*   Updated: 2025/11/10 15:19:04 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"

template <typename T>
auto easyFind(T &container, int tofind)
{
	auto it{std::find(std::begin(container), std::end(container), tofind)};
	if(it == std::end(container))
		throw std::exception();
	return it;
}