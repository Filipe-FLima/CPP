/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:20:50 by flima             #+#    #+#             */
/*   Updated: 2025/10/16 21:28:45 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_H
# define AForm_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	private:
		const std::string		name;
		bool					is_signed;
		const int				gradeToSign;
		const int				gradeToExecute;
		
	public:
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string			getName() const;
		std::string			getFormStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& b);
		void				execute(Bureaucrat const& executor) const;
		virtual void		action() const = 0;

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
	class NotSignedException: public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif