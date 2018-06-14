//
// Created by Roman KYSLYY on 6/11/18.
//

#ifndef GIT_CPP_ISPACEMARINE_HPP
#define GIT_CPP_ISPACEMARINE_HPP

# include <iostream>

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine(void) {}
	virtual ISpaceMarine* clone(void) const = 0;
	virtual void battleCry(void) const = 0;
	virtual void rangedAttack(void) const = 0;
	virtual void meleeAttack(void) const = 0;
};

#endif //GIT_CPP_ISPACEMARINE_HPP
