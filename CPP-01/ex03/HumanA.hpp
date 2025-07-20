/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:02:35 by flima             #+#    #+#             */
/*   Updated: 2025/07/19 18:31:53 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon*		weapon;
		std::string	name;
		
	public:
		HumanA(const std::string& name, Weapon& weapon);
		void	attack();
};

#endif