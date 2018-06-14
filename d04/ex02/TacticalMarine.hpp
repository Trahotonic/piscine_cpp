//
// Created by Roman KYSLYY on 6/11/18.
//

#ifndef GIT_CPP_TACTICALMARINE_HPP
#define GIT_CPP_TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine(void);
	TacticalMarine(TacticalMarine const & src);

	TacticalMarine	&operator=(TacticalMarine const & src);

	~TacticalMarine(void);

	ISpaceMarine	*clone(void) const;
	void			battleCry(void) const;
	void			rangedAttack(void) const;
	void 			meleeAttack(void) const;
};

#endif //GIT_CPP_TACTICALMARINE_HPP
