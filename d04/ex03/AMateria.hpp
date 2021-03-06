//
// Created by Roman KYSLYY on 6/14/18.
//

#ifndef GIT_CPP_AMATERIA_HPP
#define GIT_CPP_AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class AMateria
{
private:
	unsigned int	xp_;
	std::string		type_;
public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & src);

	AMateria	&operator=(AMateria const & src);

	virtual ~AMateria(void);

	std::string	const & getType(void) const;
	unsigned int getXP(void) const;

	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter & target);
};

#endif //GIT_CPP_AMATERIA_HPP
