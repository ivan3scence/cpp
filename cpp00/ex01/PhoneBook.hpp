#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# include "Contact.hpp"

# define MAX_CONTACTS 3

class	PhoneBook
{
private:
	Contact	_contacts[8];
	int 	_last;

	void	print_contacts(void) const;
public:
	PhoneBook();
	~PhoneBook();
	void	push_contacts(void);
	void 	add(void);
	void	search(void) const;
	int 	exit(void);
};

#endif
