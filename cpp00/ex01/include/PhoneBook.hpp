#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <sstream>

# include "Contact.hpp"

# define MAX_CONTACTS 8

class	PhoneBook
{
private:
	Contact	_contacts[MAX_CONTACTS];
	int 	_quant;

	void	print_contacts(void) const;
public:
	PhoneBook(void);
	~PhoneBook();
	void	push_contacts(void);
	void 	add(void);
	void	search(void) const;
};

#endif
