#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::Contact(std::string f_name, std::string l_name, std::string nick,
			std::string phone, std::string secret)
{
	_first_name = std::string(f_name);
	_last_name = std::string(l_name);
	_nickname = std::string(nick);
	_phone = std::string(phone);
	_secret = std::string(secret);
}

Contact::~Contact()
{
	return ;
}

void Contact::display() const
{
	std::cout << _first_name << '\n'
			  << _last_name << '\n'
			  << _nickname << '\n'
			  << _phone << '\n'
			  << _secret << '\n';
}

void Contact::print_contact(void) const
{
	std::cout << _first_name << '|'
		<< _last_name << '|'
		<< _nickname << '\n';
}
