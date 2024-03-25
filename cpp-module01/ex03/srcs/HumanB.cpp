/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:45:37 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/25 14:45:39 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.h"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}

void HumanB::attack() const {
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with" << std::endl;
    }
}