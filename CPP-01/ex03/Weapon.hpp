/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:02:47 by flima             #+#    #+#             */
/*   Updated: 2025/07/19 15:07:14 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
 
class	Weapon
{
	private:
		std::string	type;	

	public:
		Weapon(const std::string& type);
		const std::string&	getType();
		void				setType(const std::string& type);
};

#endif