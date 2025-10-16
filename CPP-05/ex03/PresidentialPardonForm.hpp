/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:26:57 by flima             #+#    #+#             */
/*   Updated: 2025/10/16 20:08:36 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

#define PP_REQUIRETODSIGN 25
#define PP_REQUIREDTOEXEC 5

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	target;
	
	public:
		PresidentialPardonForm(const std::string& _target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		std::string	getTarget() const;
		void	action() const override;
};

#endif