/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:06:59 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/06 13:44:38 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) 
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
	if (!this->getSigned()) {
		throw Exceptions::NotSignedExection();
	}
	else if (executor.getGrade() > this->getRequiredExecGrade()) {
		throw Exceptions::GradeTooLowException();
	}
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file.is_open()) {
		std::perror(fileName.c_str());
		return ;
	}
    file << "         >X<         "<< std::endl;
    file << "          A          "<< std::endl;
    file << "         d$b         "<< std::endl;
    file << "       .d$$$b.       "<< std::endl;
    file << "     .d$i$$$$$b.     "<< std::endl;
    file << "        d$$$@b        "<< std::endl;
    file << "       d$$$$ib       "<< std::endl;
    file << "     .d$$$$$$$b      "<< std::endl;
    file << "   .d$$@$$$$$$$ib.   "<< std::endl;
    file << "       d$$i$$$b       "<< std::endl;
    file << "      d$$$$$@$b      "<< std::endl;
    file << " .d$$$$i$$$$$$$$$$b. "<< std::endl;
    file << "   .d$@$$$$$$$$@b.   "<< std::endl;
    file << "         ###         "<< std::endl;
    file << "         ###         "<< std::endl;
    file << "         ###         "<< std::endl;
    file.close();
}
