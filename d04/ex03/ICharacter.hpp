//
// Created by Roman KYSLYY on 6/14/18.
//

#ifndef GIT_CPP_ICHARACTER_HPP
#define GIT_CPP_ICHARACTER_HPP

# include <iostream>

class ICharacter
{
private:
	AMateria	*inventory[4];
public:
	virtual ~ICharacter() {}
	virtual std::string const	&getName(void) const = 0;
	virtual void				equip(AMateria *m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter & target) = 0;
};

#endif //GIT_CPP_ICHARACTER_HPP
