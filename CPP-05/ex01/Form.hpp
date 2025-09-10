/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:20:50 by flima             #+#    #+#             */
/*   Updated: 2025/09/10 12:52:26 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	private:
		const std::string		name;
		bool					is_signed;
		const int				gradeToSign;
		const int				gradeToExecute;
		
	public:
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string			getName() const;
		std::string			getFormStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& b);

	class GradeTooHighException: public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
	
	class GradeTooLowException: public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif