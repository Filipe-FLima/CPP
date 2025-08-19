/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:43:00 by flima             #+#    #+#             */
/*   Updated: 2025/08/13 14:01:51 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class	Brain
{
	private:
		std::string ideas[100];
	
		public:
			Brain();
			Brain(const Brain& other);
			Brain& operator=(const Brain& other);
			~Brain();
			
};

#endif