/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:33:13 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/06 13:41:23 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Exception.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
	/* Constructors and destructor */
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const & rhs);

	Bureaucrat(std::string const & name, int const & grade);

	std::string getName() const;
	int 		getGrade() const;

	void 		incrementGrade();
	void 		decrementGrade();
	void		signForm(AForm &form);
	void 		executeForm(const AForm & form) const;

private:
	const std::string	_name;
	int 				_grade;

	Bureaucrat();
};

std::ostream & operator<<(std::ostream & out, const Bureaucrat & src);