#include <iostream>

int	main(void)
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*ptr=&str;
	std::string	&ref=str;

	std::cout << "\n\n" << &str << ": string address\n"
				<< &ptr << ": pointer address\n"
				<< &ref << ": reference address\n"
				<< str << ": string value\n"
				<< ptr << ": pointer value\n"
				<< ref << ": reference value\n\n\n";
}
