/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:53:53 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/06 13:41:40 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat::~Bureaucrat() 
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) 
{
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade)
{
	if (this->_grade > 150) {
		throw Exceptions::GradeTooLowException();
	}
	else if (this->_grade < 1) {
		throw Exceptions::GradeTooHighException();
	}
}

std::string Bureaucrat::getName() const 
{
	return this->_name;
}

int Bureaucrat::getGrade() const 
{
	return this->_grade;
}

void Bureaucrat::incrementGrade() 
{
	if (this->_grade - 1 < 1)
		throw Exceptions::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() 
{
	if (this->_grade + 1 > 150)
		throw Exceptions::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form) 
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (Exceptions::GradeTooLowException &e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() <<
			" because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const 
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << this->_name << " couldn't execute " << form.getName() << " because: "
			<< e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) 
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}