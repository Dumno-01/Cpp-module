/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-26 16:59:27 by ffreze            #+#    #+#             */
/*   Updated: 2024-03-26 16:59:27 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main() {
	ClapTrap claptrap("CL4P-TP");

	claptrap.attack("Bandit");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);

	ScavTrap scavtrap("SC4V-TP");

	scavtrap.attack("Bandit");
	scavtrap.takeDamage(3);
	scavtrap.beRepaired(2);

	scavtrap.guardGate();

	return 0;
}