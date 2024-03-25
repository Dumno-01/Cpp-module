/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:42:42 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/20 10:42:53 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif