/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:30:49 by flima             #+#    #+#             */
/*   Updated: 2025/09/03 20:40:43 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int &gradeToSign, int &gradeToExecute): name(name),
	gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	is_signed = false;
}

Form::Form(const Form &other): name(other.name), is_signed(other.is_signed),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
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
