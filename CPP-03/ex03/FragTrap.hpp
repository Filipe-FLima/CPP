/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:07:32 by flima             #+#    #+#             */
/*   Updated: 2025/08/10 15:18:14 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

# define FRAG_HP 10
# define FRAG_ATTACK 3
# define FRAG_ENGY 10
# define FRAG_REPAIR 0.5
	
class FragTrap : virtual public ClapTrap
{
	protected:
		unsigned int Frag_hitPoints;
		unsigned int Frag_attackDamage;
	public:
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();
		void 	attack(const std::string& target) override;
		void	highFivesGuys(void);
		
};

#endif