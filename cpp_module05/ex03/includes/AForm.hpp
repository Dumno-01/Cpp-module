/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:32:43 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/02 08:40:36 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Exception.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm(AForm const & src);
	virtual ~AForm();
	AForm & operator=(AForm const & src);

	AForm(std::string const & name, int const & gradeToSign, int const & gradeToExecute);

	std::string getName() const;
	int 		getRequiredSignGrade() const;
	int 		getRequiredExecGrade() const;
	bool 		getSigned() const;

	void			beSigned(const Bureaucrat& bur);
	virtual void	execute(Bureaucrat const & executor) const = 0;

private:
	const std::string	_name;
	bool 				_signed;
	const int 			_requiredSignGrade;
	const int 			_requiredExecGrade;

	AForm();
};

std::ostream & operator<<(std::ostream & out, AForm & src);