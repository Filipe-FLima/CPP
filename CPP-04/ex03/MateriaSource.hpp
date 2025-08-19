/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:14:14 by flima             #+#    #+#             */
/*   Updated: 2025/08/18 14:14:49 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"

# define slot 4

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	templates[slot];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();

		void 		learnMateria(AMateria*) override;
		AMateria* 	createMateria(std::string const & type) override;
		void		cleanTemplates();

};

#endif