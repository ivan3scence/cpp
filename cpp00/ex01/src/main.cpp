#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::string	line;
	PhoneBook	book;

	while (1)
	{
		std::cout << "$> ";
		getline(std::cin, line);
		if (line == "ADD")
			book.add();
		else if (line == "SEARCH")
			book.search();
		else if (line == "EXIT")
			std::exit(0);
		else
			std::cout << "program knows only:\n\tADD\n\tSEARCH\n\tEXIT\n";
	}
}