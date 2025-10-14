/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:30:49 by flima             #+#    #+#             */
/*   Updated: 2025/10/14 20:01:45 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute):
	name(name),
	gradeToSign(gradeToSign), 
	gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAXGRADE || gradeToExecute < MAXGRADE)
		throw GradeTooHighException();
	else if (gradeToSign > MINGRADE || gradeToExecute > MINGRADE)
		throw GradeTooLowException();
		
	is_signed = false;
}

Form::Form(const Form &other): 
	name(other.name), 
	is_signed(other.is_signed),
	gradeToSign(other.gradeToSign), 
	gradeToExecute(other.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return name;
}
std::string Form::getFormStatus() const
{
	if (is_signed)
		return "is signed";
	return "is not signed";
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	is_signed = true;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "grade higher than MaxGrade.";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "grade lower than required.";
}


std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << ", " << obj.getFormStatus() << 
		". The grades required to sign and execute are " <<
		obj.getGradeToSign() << " and " << obj.getGradeToExecute() 
		<< ", respectively.";
	
	return os;
}