/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:22:26 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/25 13:22:33 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string _type;

public:
    Weapon(std::string type);
    const std::string& getType() const;
    void setType(std::string type);
};

#endif