//
// Created by Roman KYSLYY on 6/14/18.
//

#ifndef GIT_CPP_CHARACTER_HPP
#define GIT_CPP_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string	_name;
    AMateria	*inventory[4];
public:
    Character(void);
    Character(Character const & src);
    Character(std::string const & name);

    Character   &operator=(Character const & src);

    ~Character(void);

    std::string const   &getName(void) const;
    void                equip(AMateria *m);
    void                unequip(int idx);
    void                use(int idx, ICharacter & target);
};

#endif //GIT_CPP_CHARACTER_HPP
