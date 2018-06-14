//
// Created by Roman KYSLYY on 6/14/18.
//

#ifndef GIT_CPP_MATERIASOURCE_HPP
#define GIT_CPP_MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*materias[4];
public:
	void		learnMateria(AMateria * newMateria);
	AMateria	*createMateria(std::string const & type);
};

#endif //GIT_CPP_MATERIASOURCE_HPP
