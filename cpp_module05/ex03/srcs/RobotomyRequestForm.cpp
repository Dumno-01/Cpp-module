/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:06:19 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/06 13:37:08 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) 
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
	if (!this->getSigned()) {
		throw Exceptions::NotSignedExection();
	}
	else if (executor.getGrade() > this->getRequiredExecGrade()) {
		throw Exceptions::GradeTooLowException();
	}
	static int i;
	if (i % 2 == 0) {
		std::cout << "BZZZZZT! " << this->_target << " has been robotomized!" << std::endl;
	}
	else {
		std::cout << "Robotomy failed! " << this->_target << " is still alive." << std::endl;
	}
	i++;
}