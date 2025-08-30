/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:53:00 by flima             #+#    #+#             */
/*   Updated: 2025/08/27 11:51:14 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_H
# define FLOOR_H

# include "AMateria.hpp"

# define FLOOR_LIM 2

class Floor
{
	private:
		AMateria* 		floor[FLOOR_LIM];
		unsigned int	onFloor;
	public:
		Floor();
		Floor(const Floor& other);
		Floor& operator=(const Floor& other);
		~Floor();

		void	dropOnFloor(AMateria *m);
		void	cleanFloor();
};


#endif