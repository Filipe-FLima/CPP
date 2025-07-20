/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:02:40 by flima             #+#    #+#             */
/*   Updated: 2025/07/19 18:32:00 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon*		weapon;
		std::string	name;
		
	public:
		HumanB(const std::string& name);
		void	setWeapon(Weapon& weapon);
		void	attack();

};

#endif