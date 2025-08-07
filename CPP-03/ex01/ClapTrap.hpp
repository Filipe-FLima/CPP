/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:29:27 by flima             #+#    #+#             */
/*   Updated: 2025/08/06 19:07:59 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
#include <iomanip>

# define STATS 10
# define ATK 0
# define ENERGY 1
# define REPAIR 0.1	


class	ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
		bool			outOfEnergy;
		
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		const std::string&	getName() const;
		bool				checkEnergy();
		unsigned int		getHitPoints();
		unsigned int		getEnergyPoints();
		unsigned int		getAttackDamage();
		bool				is_alive();
};



#endif