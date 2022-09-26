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

//Contact::~Contact()
//{
//	return ;
//}

void Contact::display() const
{
	std::cout << _first_name << '\n'
			  << _last_name << '\n'
			  << _nickname << '\n'
			  << _phone << '\n'
			  << _secret << '\n';
}

static void print_string(std::string str)
{
	std::string	output;
	int			len;

	len = str.length();
	if (len < 11)
	{
		str.resize(10, 32);
		std::cout << str << "|";
	}
	else
	{
		str.resize(9);
		std::cout << str << ".|";
	}
}

void Contact::print_contact(void) const
{
	print_string(_first_name);
	print_string(_last_name);
	print_string(_nickname);
	std::cout << std::endl;
}