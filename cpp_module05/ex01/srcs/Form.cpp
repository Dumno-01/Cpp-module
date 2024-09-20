/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:41:47 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/01 03:43:46 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Default form created with grade to exec " << this->getGradeToExec() \
		<< " and grade to sign " << this->getGradeToSign() << "." << std::endl;
}

Form::Form(std::string name, unsigned int gradeExec, unsigned int gradeSign) : _name(name), _signed(false), _gradeToSign(gradeSign),_gradeToExec(gradeExec) 
{
	if (gradeExec > 150 || gradeSign > 150)
		throw(GradeTooLowException());
	if (gradeExec < 1 || gradeSign < 1)
		throw(GradeTooHighException());
	std::cout << "Form named "<< this->getName() << " created with grade to exec " << this->getGradeToExec()
			  << " and grade to sign " << this->getGradeToSign() << "." << std::endl;
}

Form::~Form()
{
	std::cout << "Form named " << this->getName() << " with grade to exec " << this->getGradeToExec()
			  << " and grade to sign " << this->getGradeToSign() << " deleted." << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << "Form named " << this->getName() << " created with grade to exec " << this->getGradeToExec()
			  << " and grade to sign " << this->getGradeToSign() << "." << std::endl;
}

Form &Form::operator=(const Form &other)
{
	this->_signed = other._signed;
	return (*this);
}

bool Form::isSigned() const
{
	if (this->_signed == true)
		return (true);
	else
		return (false);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (this->isSigned() == true)
	{
		std::cout << "Form named " << this->getName() << " is already signed." << std::endl;
		return ;
	}
	if (b.getGrade() <= this->getGradeToSign())
	{
		this->_signed = true;
	}
	else
		throw GradeTooLowException();
}

unsigned int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

unsigned int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

std::string Form::getName() const
{
	return (this->_name);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high for form.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Grade too low for form.");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form " << f.getName();
	if (f.isSigned())
		out << " is signed, ";
	else
		out << " is not signed, ";
	out << "and the grade needed to sign it is " << f.getGradeToSign() << ", and the grade needed to execute it is " << f.getGradeToExec() << ".";
	return (out);
}