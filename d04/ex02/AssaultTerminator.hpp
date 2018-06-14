//
// Created by Roman KYSLYY on 6/11/18.
//

#ifndef GIT_CPP_ASSAULTTERMINATOR_HPP
#define GIT_CPP_ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssauntTerminator : public ISpaceMarine
{
public:
	AssauntTerminator(void);
	AssauntTerminator(AssauntTerminator const & src);

	AssauntTerminator	&operator=(AssauntTerminator const & src);

	~AssauntTerminator(void);

	ISpaceMarine	*clone(void) const;
	void			battleCry(void) const;
	void			rangedAttack(void) const;
	void 			meleeAttack(void) const;
};

#endif //GIT_CPP_ASSAULTTERMINATOR_HPP
