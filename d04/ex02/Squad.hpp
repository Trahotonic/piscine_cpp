//
// Created by Roman KYSLYY on 6/11/18.
//

#ifndef GIT_CPP_SQUAD_HPP
#define GIT_CPP_SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
private:
	int			unitCount;
	t_container	*marines;
public:
	Squad(void);

	int				getCount(void) const;
	ISpaceMarine	*getUnit(int) const;
	int				push(ISpaceMarine*);
};


#endif //GIT_CPP_SQUAD_HPP
