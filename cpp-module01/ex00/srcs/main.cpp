/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 07:33:49 by ffreze            #+#    #+#             */
/*   Updated: 2024/03/19 07:34:06 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.h"

int main() {
    Zombie zombie1("Alice");
    zombie1.announce();

    Zombie* zombie2 = newZombie("Bob");
    zombie2->announce();
    delete zombie2;

    randomChump("Charlie");

    return 0;
}