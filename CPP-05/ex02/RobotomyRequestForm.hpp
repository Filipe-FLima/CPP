/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:27:02 by flima             #+#    #+#             */
/*   Updated: 2025/10/16 20:08:48 by filipe           ###   ########.fr       */
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
	
	public:
		RobotomyRequestForm(const std::string& _target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string	getTarget() const;
		void	action() const override;
};

#endif