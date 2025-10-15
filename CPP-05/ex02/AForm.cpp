/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:30:49 by flima             #+#    #+#             */
/*   Updated: 2025/10/14 20:13:00 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute):
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

AForm::AForm(const AForm &other): 
	name(other.name), 
	is_signed(other.is_signed),
	gradeToSign(other.gradeToSign), 
	gradeToExecute(other.gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return name;
}
std::string AForm::getFormStatus() const
{
	if (is_signed)
		return "is signed";
	return "is not signed";
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!is_signed)
		throw NotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	action();
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "grade higher than MaxGrade.";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "grade lower than required.";
}

const char *AForm::NotSignedException::what() const noexcept
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << ", " << obj.getFormStatus() << 
		". The grades required to sign and execute are " <<
		obj.getGradeToSign() << " and " << obj.getGradeToExecute() 
		<< ", respectively.";
	
	return os;
}


