#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>

class	Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;
public:
	Contact(void);
	Contact(std::string f_name, std::string l_name, std::string nick,
			std::string phone, std::string secret);
//	~Contact();
	void print_contact(void) const;
	void display(void) const;
};

#endif
