#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &mat)
{
	*this = mat;
}

MateriaSource	&MateriaSource::operator = (const MateriaSource &mat)
{
	if (this == *mat)
		return (*this);
	_materias = mat.getMaterias();
	return (*this);
}

MatriaSource::~MateriaSource(void)
{
	for (int i=0; i < 4; ++i)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

AMateria	*MateriaSource::getMaterias(void) const
{
	AMateria	*tmp[4];

	for (int i=0; i < 4; ++i)
		tmp[i] = _materias[i];
	return (tmp);
}

void	MateriaSource::learnMateria(AMateria *mat)
{
	for (int i=0; i < 4; ++i)
	{
		if (!_materias[i])
		{
			_materias[i] = mat;
			return ;
		}
	}
	std::cout << "no slots in MateriaSource!\n";
}

AMateria	*MateriaSourse::createMateria(std::string const &type)
{
	for (int i = 3; i > -1; --i)
	{
		if (_materias[i].getName() == type)
			(return (new AMateria(_materias[i])));
	}
	return (0);
}