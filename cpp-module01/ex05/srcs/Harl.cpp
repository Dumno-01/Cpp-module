/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-26 15:56:11 by ffreze            #+#    #+#             */
/*   Updated: 2024-03-26 15:56:11 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.h"
#include <iostream>

void Harl::debug() {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info() {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::warning() {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "ERROR: This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    typedef void (Harl::*ComplaintFunction)();
    ComplaintFunction complaintFunction = NULL;

    if (level == "DEBUG") {
        complaintFunction = &Harl::debug;
    } else if (level == "INFO") {
        complaintFunction = &Harl::info;
    } else if (level == "WARNING") {
        complaintFunction = &Harl::warning;
    } else if (level == "ERROR") {
        complaintFunction = &Harl::error;
    }

    if (complaintFunction) {
        (this->*complaintFunction)();
    } else {
        std::cout << "Invalid complaint level: " << level << std::endl;
    }
}