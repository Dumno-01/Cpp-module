/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:45:18 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/25 14:45:19 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/HumanA.h"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack() const {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}