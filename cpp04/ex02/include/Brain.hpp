#ifndef __BRAIN_H__
#define __BRAIN_H__

# include <iostream>
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define GRAY "\x1B[90m"
# define END "\033[0m"

class Brain
{
public:
	Brain(void);
	Brain(std::string name);
	Brain(const Brain &Brain);
	~Brain(void);
	Brain(std::string ids[100]);
	Brain	&operator = (const Brain &brain);

	void		setIdeas(const std::string ids[100]);
	void 		print(void) const;
protected:
	std::string	ideas[100];
};

#endif
