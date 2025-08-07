/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:04:56 by flima             #+#    #+#             */
/*   Updated: 2025/08/07 20:41:52 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

# define HP 10
# define ATTACK 2
# define ENGY 0.6
# define REPAIR_SCAV 1
	
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
		void 	attack(const std::string& target) override;
		void	guardGate();
		
};

#endif