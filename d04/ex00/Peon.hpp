//
// Created by Roman Kyslyy on 6/10/18.
//

#ifndef PISCINE_CPP_PEON_HPP
#define PISCINE_CPP_PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
public:
    Peon(void);
    Peon(std::string name);
    Peon(Peon const & src);

    ~Peon(void);

    Peon    &operator=(Peon const & src);

    void        getPolymorphed(void) const;
};

#endif //PISCINE_CPP_PEON_HPP
