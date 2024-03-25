#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook
{
	public :
		PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void) const;
	private :
		Contact	_contacts[8];
		int		_nb_contacts;
		int		_index;
};

#endif