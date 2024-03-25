#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
	public :
		Contact(void);
		int		fill_contact(void);
		void	print_contact(void) const;
		void	print_search(int index) const;
	private :
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

std::string truncateString(const std::string& str, size_t width);

#endif