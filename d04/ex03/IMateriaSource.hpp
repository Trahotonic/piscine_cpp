//
// Created by Roman KYSLYY on 6/14/18.
//

#ifndef GIT_CPP_IMATERIASOURCE_HPP
#define GIT_CPP_IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource(void) {}
	virtual void	learnMateria(AMateria*) = 0;
	virtual AMateria	*createMateria(std::string const & type) = 0;
};

#endif //GIT_CPP_IMATERIASOURCE_HPP
