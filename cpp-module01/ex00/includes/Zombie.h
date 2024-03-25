/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 07:50:24 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/19 07:50:33 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
public:
    Zombie(std::string name);
    ~Zombie();
    void announce() const;
private:
    std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif