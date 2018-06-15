//
// Created by Roman KYSLYY on 6/14/18.
//

#ifndef GIT_CPP_ICE_HPP
#define GIT_CPP_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice(void);
    Ice(std::string const & type);
    Ice(Ice const & src);

    ~Ice(void);

    Ice &operator=(Ice const & src);

    AMateria     *clone(void) const;
    void    use(ICharacter & target);
};

#endif //GIT_CPP_ICE_HPP
