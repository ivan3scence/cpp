#ifndef __HARL_H__
#define __HARL_H__

# include <iostream>

class Harl
{
public:

	Harl(void);
	~Harl(void);

	void		complain(std::string level) const;
	int			getLevel(std::string level) const;

private:
	void		debug(void) const;
	void		info(void) const;
	void		warning(void) const;
	void		error(void) const;
};

typedef void	(Harl::*funcPtr)(void) const;

#endif
