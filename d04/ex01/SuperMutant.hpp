//
// Created by Roman Kyslyy on 6/10/18.
//

#ifndef PISCINE_CPP_SUPERMUTANT_HPP
#define PISCINE_CPP_SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public virtual Enemy
{
public:

    SuperMutant(void);
    SuperMutant(SuperMutant const & src);
    SuperMutant(int hp, std::string const & type);

    SuperMutant &operator=(SuperMutant const & src);

    ~SuperMutant(void);

    void    takeDamage(int amount);
};

#endif //PISCINE_CPP_SUPERMUTANT_HPP
