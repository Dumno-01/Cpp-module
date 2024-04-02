/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-26 16:29:04 by ffreze            #+#    #+#             */
/*   Updated: 2024-03-26 16:29:04 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c( 2.5f );
    Fixed d( -3.0f );

    std::cout << "Test des opérateurs d'incrémentation et de décrémentation" << std::endl;
    std::cout << "Initial value of a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "Test des opérateurs arithmétiques" << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;

    std::cout << "Test des opérateurs de comparaison" << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;

    std::cout << "Test des fonctions min et max" << std::endl;
    std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
    std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;

    std::cout << "Test avec des valeurs constantes" << std::endl;
    std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;

    return 0;
}