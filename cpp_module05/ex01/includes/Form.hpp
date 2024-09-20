/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:40:55 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/01 03:43:41 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExec;
public:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	Form();
	Form(std::string name, unsigned int gradeExec, unsigned int gradeSign);
	~Form();
	Form(const Form &other);
	Form& operator=(const Form &other);
	void beSigned(const Bureaucrat &bureaucrat);
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExec() const;
	std::string getName() const;
	bool isSigned() const;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif