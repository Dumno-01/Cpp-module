/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-26 17:09:22 by ffreze            #+#    #+#             */
/*   Updated: 2024-03-26 17:09:22 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(100), energyPoints(50), attackDamage(20) {
	std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " can't attack. Not enough hit points or energy points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0 && amount < static_cast<unsigned int>(hitPoints)) {
		hitPoints -= static_cast<int>(amount);
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can't take any more damage. It's out of hit points." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints > 0 && energyPoints > 0) {
		hitPoints += static_cast<int>(amount);
		energyPoints--;
		std::cout << "ClapTrap " << name << " is repaired and gains " << amount << " hit points!" << std::endl;
	} else if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't be repaired. It's out of hit points." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can't be repaired. It's out of energy points." << std::endl;
	}
}

int ClapTrap::getHitPoints() const {
	return hitPoints;
}