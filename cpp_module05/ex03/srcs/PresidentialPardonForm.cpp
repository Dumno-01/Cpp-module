/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:05:53 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/06 13:37:13 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("RobotomyRequestForm", 25, 5), _target(target) 
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) 
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
	if (!this->getSigned()) {
		throw Exceptions::NotSignedExection();
	}
	else if (executor.getGrade() > this->getRequiredExecGrade()) {
		throw Exceptions::GradeTooLowException();
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}