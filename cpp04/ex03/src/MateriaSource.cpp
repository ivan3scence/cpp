#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i=0; i < 4; ++i)
		_materias[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &mat)
{
	*this = mat;
}

MateriaSource	&MateriaSource::operator = (const MateriaSource &mat)
{
	if (this == &mat)
		return (*this);
	mat.getMaterias(_materias);
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i=0; i < 4; ++i)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

void	MateriaSource::getMaterias(AMateria* (&to)[4]) const
{
	for (int i=0; i < 4; ++i)
		to[i] = _materias[i];
}

void	MateriaSource::learnMateria(AMateria *mat)
{
	for (int i=0; i < 4; ++i)
	{
		if (!_materias[i])
		{
			_materias[i] = mat;
			std::cout << mat->getType() << std::endl;
			return ;
		}
	}
	std::cout << "no slots in MateriaSource!\n";
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 3; i >= 0; --i)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (0);
}