/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-26 16:44:28 by ffreze            #+#    #+#             */
/*   Updated: 2024-03-26 16:44:28 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main() {
	ClapTrap claptrap("CL4P-TP");

	claptrap.attack("Bandit");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	std::cout << "CL4P-TP's hit points: " << claptrap.getHitPoints() << std::endl;

	// Test d'attaque et de réparation avec des points de vie et d'énergie suffisants
	ClapTrap claptrap2("Another CL4P-TP");
	claptrap2.attack("Skag");
	claptrap2.takeDamage(2);
	claptrap2.beRepaired(4);
	std::cout << "Another CL4P-TP's hit points: " << claptrap.getHitPoints() << std::endl;

	// Test d'attaque sans suffisamment d'énergie
	ClapTrap claptrap3("Low Energy CL4P-TP");
	for (int i = 0; i < 10; i++){
		claptrap3.attack("Spiderant");
	}
	claptrap3.attack("Spiderant");

	// Test de dommages sans suffisamment de points de vie
	ClapTrap claptrap4("Fragile CL4P-TP");
	claptrap4.takeDamage(20);

	// Test de réparation sans suffisamment de points de vie
	ClapTrap claptrap5("Nearly Destroyed CL4P-TP");
	claptrap5.beRepaired(15);

	return 0;
}