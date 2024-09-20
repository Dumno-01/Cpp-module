/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:53:42 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/06 13:54:57 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	(void) src;
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	std::string formNames[3] = {
			"robotomy request",
			"shrubbery creation",
			"presidential pardon"
	};
	int index = 0;
	while (index < 3) {
		if (name == formNames[index]) {
			break ;
		}
		index++;
	}
	AForm *form;
	switch (index) {
		case 0:
			form = new RobotomyRequestForm(target);
			break ;
		case 1:
			form = new ShrubberyCreationForm(target);
			break ;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << name << " is not a valid form name" << std::endl;
			form = NULL;
			break ;
	}
	if (form != NULL) {
		std::cout << "Intern creates " << name << std::endl;
	}
	return form;
}