/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:27:07 by flima             #+#    #+#             */
/*   Updated: 2025/10/16 20:08:59 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <fstream>

#define SC_REQUIRETODSIGN 145
#define SC_REQUIREDTOEXEC 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	
	public:
		ShrubberyCreationForm(const std::string& _target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		std::string	getTarget() const;
		void	action() const override;
};

#endif