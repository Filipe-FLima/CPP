/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:53:00 by flima             #+#    #+#             */
/*   Updated: 2025/11/05 14:13:49 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"

template <typename T>
auto easyfind(T &container, int tofind)
{
	auto it{std::find(std::begin(container), std::end(container), tofind)};
	if(it == std::end(container))
		throw std::exception();
	return it;
}