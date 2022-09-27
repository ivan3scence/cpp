#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

# include <string>
# include <iostream>

class Zombie {


public:

	std::string	getName(void);
	void 		announce(void);

	Zombie(std::string name);
	~Zombie(void);


private:
	std::string	_name;

	Zombie(void);
};

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);
#endif