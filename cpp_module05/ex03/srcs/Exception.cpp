/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:39:34 by ffreze            #+#    #+#             */
/*   Updated: 2024/08/06 13:40:56 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Exception.hpp"

const char *Exceptions::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Exceptions::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char *Exceptions::NotSignedExection::what() const throw() {
	return "Form is not signed";
}