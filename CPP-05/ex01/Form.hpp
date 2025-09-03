/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:20:50 by flima             #+#    #+#             */
/*   Updated: 2025/09/03 20:32:28 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
# include <exception>
# include <string>

class	Form
{
	private:
		const std::string		name;
		bool					is_signed;
		const int				gradeToSign;
		const int				gradeToExecute;
		
	public:
		Form(const std::string& name, int& gradeToSign, int& gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string			getName() const;
		std::string			getFormStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

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