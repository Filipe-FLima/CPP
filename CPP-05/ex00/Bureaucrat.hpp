/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:58:56 by flima             #+#    #+#             */
/*   Updated: 2025/10/17 18:40:18 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
# include <exception>
# include <string>

# define	MAXGRADE 1
# define	MINGRADE 150

class	Bureaucrat
{
	private:
		const std::string		name;
		int						grade;
		
	public:
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string			getName() const;
		int					getGrade() const;
		void				gradeUp();
		void				gradeDown();
	
	
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif