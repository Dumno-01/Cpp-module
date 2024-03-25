/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:54:47 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/20 10:54:49 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.h"
#include <iostream>

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; ++i) {
        new (&horde[i]) Zombie(name); // Construit directement l'objet dans horde[i]
    }

    return horde;
}