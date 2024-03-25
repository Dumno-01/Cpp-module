/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:53:36 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/20 10:53:42 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.h"
#include <iostream>

int main() {
    int numZombies = 5;
    Zombie* horde = zombieHorde(numZombies, "Horde Zombie");

    for (int i = 0; i < numZombies; ++i) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}