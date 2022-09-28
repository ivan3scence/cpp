#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

// # include <string>
# include <iostream>
// # include <cstdlib>

class Zombie {


public:

	void 	announce(void);
	void 	setName(std::string name);

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);


private:
	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);
#endif
