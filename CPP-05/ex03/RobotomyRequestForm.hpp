/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:27:02 by flima             #+#    #+#             */
/*   Updated: 2025/10/27 14:29:51 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

#define RR_REQUIRETODSIGN 72
#define RR_REQUIREDTOEXEC 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
		
	protected:
		void	action() const override;
	public:
		RobotomyRequestForm(const std::string& _target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string	getTarget() const;
};

#endif