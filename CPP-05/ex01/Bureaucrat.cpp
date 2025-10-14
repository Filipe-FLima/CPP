/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:58:59 by flima             #+#    #+#             */
/*   Updated: 2025/10/14 19:56:55 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : name(name)
{
	if (grade < MAXGRADE)
		throw GradeTooHighException();
	else if (grade > MINGRADE)
		GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::gradeUp()
{
	if (grade - 1 < MAXGRADE)
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::gradeDown()
{
	if (grade + 1 > MINGRADE)
		throw GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << name << " couldn`t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade higher than MaxGrade.";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade lower than MinGrade.";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
