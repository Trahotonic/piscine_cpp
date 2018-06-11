//
// Created by Roman KYSLYY on 6/11/18.
//

#ifndef GIT_CPP_ISQUAD_HPP
#define GIT_CPP_ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
public:
	virtual ~ISquad(void) {}
	virtual int getCount() const = 0;
	virtual ISpaceMarine*	getUnit(int) const  = 0;
	virtual int push(ISpaceMarine*) = 0;
};

#endif //GIT_CPP_ISQUAD_HPP
