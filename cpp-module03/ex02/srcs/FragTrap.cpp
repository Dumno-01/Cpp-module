/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-26 17:09:41 by ffreze            #+#    #+#             */
/*   Updated: 2024-03-26 17:09:41 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " is ready to frag and trap!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " is turned to rusty pieces!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (getHitPoints() > 0 && energyPoints > 0) {
		std::cout << "FragTrap " << name << " attacks " << target << " with a powerful blast, causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "FragTrap " << name << " can't attack. Not enough hit points or energy points." << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " requests a high five from the guys! Give me five!" << std::endl;
}