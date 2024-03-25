/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:46:00 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/20 10:47:42 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.h"
#include <iostream>

Zombie::Zombie() : _name("") {} 

Zombie::Zombie(std::string name) : _name(name) {}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name << ": BraiiiiiiinnnzzzZ... (destroyed)" << std::endl;
}