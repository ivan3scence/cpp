#ifndef __MATERIASOURCE_H__
# define __MATERIASOURCE_H__

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_materias[4];
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &mat);
	~MateriaSource(void);
	MateriaSource	&operator = (const MateriaSource &mat);

	void		learnMateria(AMateria*);
	AMateria	*createMateria(std::string const & type);
	AMateria	*getMaterias(void) const;
};

#endif