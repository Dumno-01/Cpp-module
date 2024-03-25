#include "PhoneBook.h"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook(void){
	_nb_contacts = 0;
	_index = 0;
}

void PhoneBook::add_contact(void) {
    if (_index == 8)
        _index = 0;

    // Appeler fill_contact et vérifier le retour
    if (_contacts[_index].fill_contact() == 0) {
        // Si fill_contact retourne 0, l'ajout est réussi
        _index++;
        if (_nb_contacts < 8)
            _nb_contacts++;
    } else {
        // Si fill_contact retourne 1, ne rien faire
        std::cout << "Contact not added due to missing information." << std::endl;
    }
}

void PhoneBook::search_contact() const {
    if (_nb_contacts == 0) {
        std::cout << "Phone book is empty. No contacts to search." << std::endl;
        return;
    }
    std::cout << "   Index   | First Name | Last Name  | Nickname" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
    for (int i = 0; i < _nb_contacts; ++i) {
        _contacts[i].print_search(i);
    }
    int index;
	index = 0;
    std::cout << "Enter index of the contact to view details: ";
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid index." << std::endl;
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
    }
    if (index >= 1 && index <= _nb_contacts) {
        _contacts[index - 1].print_contact();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}