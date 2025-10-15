/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:26:57 by flima             #+#    #+#             */
/*   Updated: 2025/10/15 19:33:00 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

#define REQUIRETODSIGN 25
#define REQUIREDTOEXEC 5

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	
	public:
		PresidentialPardonForm(const std::string& _target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void	action() const override;
};

#endif