#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_quant = 0;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void PhoneBook::push_contacts(void)
{
	if (_quant == MAX_CONTACTS)
		--_quant;
	for (int i = _quant; i > 0 ; --i)
		_contacts[i] = _contacts[i - 1];
	++_quant;
}

void PhoneBook::add(void)
{
	std::string f_name;
	std::string l_name;
	std::string nick;
	std::string phone;
	std::string secret;

	std::cout << "please, enter first name: ";
	std::getline(std::cin, f_name);
	std::cout << "please, enter last name: ";
	std::getline(std::cin, l_name);
	std::cout << "please, enter nickname: ";
	std::getline(std::cin, nick);
	std::cout << "please, enter phone number: ";
	std::getline(std::cin, phone);
	std::cout << "please, enter darkest secret: ";
	std::getline(std::cin, secret);
	PhoneBook::push_contacts();
	_contacts[0] = Contact(f_name, l_name, nick, phone, secret);
}

void PhoneBook::search(void) const
{
	std::string	ind;
	int index;

	index = -1;
	if (_quant == 0)
	{
		std::cout << "There are no contacts\n";
		return ;
	}
	PhoneBook::print_contacts();
	while (index < 1 || index > _quant)
	{
		std::cout << "Choose contact's index: ";
		std::getline(std::cin, ind);
		if (std::cin.eof())
			std::exit(0);
		std::stringstream(ind) >> index;
		if (index < 1 || index > _quant)
			std::cout << "Index must be in range [1;" << _quant << "]\n";
	}
	_contacts[index - 1].display();
}

void PhoneBook::print_contacts(void) const
{
	for (int i = 0; i < _quant; ++i)
	{
		std::cout << i + 1 << "        |";
		_contacts[i].print_contact();
	}
}
