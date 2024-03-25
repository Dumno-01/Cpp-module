/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:21:40 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/25 13:21:46 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <string>

class HumanA {
private:
    std::string _name;
    Weapon& _weapon;

public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
};

#endif