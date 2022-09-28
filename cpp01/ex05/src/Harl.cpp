#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	// std::cout << "Harl was destructed\n";
}

int	Harl::getLevel(std::string level) const
{
	std::string	levels[4]={"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level) const
{
	funcPtr	ptr[4]={&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int	lvl;

	lvl = Harl::getLevel(level);
	if (lvl == -1)
	{
		std::cout << "wrong command\n";
		return ;
	}
	(this->*ptr[lvl])();
}

void	Harl::debug(void) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}