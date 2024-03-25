#include "Contact.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <stdexcept>

Contact::Contact(void) {}

int Contact::fill_contact(void) {
    std::cout << "Enter first name: ";
    std::getline(std::cin, _first_name);
    if (_first_name.empty()) {
        std::cout << ("First name cannot be empty") << std::endl;
		return 1;
    }

    std::cout << "Enter last name: ";
    std::getline(std::cin, _last_name);
    if (_last_name.empty()) {
        std::cout << ("Last name cannot be empty") << std::endl;
		return 1;
    }

    std::cout << "Enter nickname: ";
    std::getline(std::cin, _nickname);
    if (_nickname.empty()) {
        std::cout << ("Nickname cannot be empty") << std::endl;
		return 1;
    }

    std::cout << "Enter phone number: ";
    std::getline(std::cin, _phone_number);
    if (_phone_number.empty()) {
        std::cout << ("Phone number cannot be empty") << std::endl;
		return 1;
    }

    std::cout << "Enter Darkest secret: ";
    std::getline(std::cin, _darkest_secret);
    if (_darkest_secret.empty()) {
        std::cout << ("Darkest secret cannot be empty") << std::endl;
		return 1;
    }
	return (0);
}

void	Contact::print_contact(void) const{
	std::cout << "First name : " << _first_name << std::endl;
	std::cout << "Last name : " << _last_name << std::endl;
	std::cout << "Nickname : " << _nickname << std::endl;
	std::cout << "Phone number : " << _phone_number << std::endl;
	std::cout << "Darkest Secret : " << _darkest_secret << std::endl;
}

void Contact::print_search(int index) const {
    std::cout << std::setw(10) << index + 1 << " | ";
    std::cout << std::setw(10) << std::right << truncateString(_first_name, 10) << " | ";
    std::cout << std::setw(10) << std::right << truncateString(_last_name, 10) << " | ";
    std::cout << std::setw(10) << std::right << truncateString(_nickname, 10) << std::endl;
}

std::string truncateString(const std::string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    } else {
        return str;
    }
}