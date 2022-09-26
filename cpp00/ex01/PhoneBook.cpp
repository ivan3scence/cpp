#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_last = -1;
}

PhoneBook::~PhoneBook()
{}

void PhoneBook::push_contacts(void)
{
	for (int i = 0; i < MAX_CONTACTS; ++i)
	{
		this->_contacts[i + 1] = this->_contacts[i];
	}
	this->_last = 0;
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
	if (this->_last == 0)
		PhoneBook::push_contacts();
	if (this->_last == -1)
	{
		this->_contacts[0] = Contact(f_name, l_name, nick, phone, secret);
		this->_last = 1;
	}
	else
		this->_contacts[this->_last++] = Contact(f_name, l_name, nick, phone,
												 secret);
	if (this->_last > MAX_CONTACTS)
		this->_last = 0;
}

void PhoneBook::search(void) const
{
	int index;

	index = -1;
	if (this->_last == -1)
	{
		std::cout << "There are no contacts\n";
		return ;
	}
	PhoneBook::print_contacts();
	while (index < 0 || index > MAX_CONTACTS)
	{
		std::cout << "Choose contact's index: ";
		std::cin >> index;
		if (index < 0 || index > MAX_CONTACTS)
			std::cout << "Index must be in range [0;7]\n";
	}
	this->_contacts[index].display();
}

void PhoneBook::print_contacts(void) const
{
	int	last;

	last = this->_last;
	if (this->_last == 0)
		last = MAX_CONTACTS;
	for (int i = 0; i < last; ++i)
	{
		std::cout << i << '|';
		this->_contacts[i].print_contact();
	}
}