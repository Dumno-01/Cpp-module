/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:46:05 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/25 14:46:07 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.h"

Weapon::Weapon(std::string type) : _type(type) {}

const std::string& Weapon::getType() const {
    return _type;
}

void Weapon::setType(std::string type) {
    _type = type;
}