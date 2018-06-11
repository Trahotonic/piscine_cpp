//
// Created by Roman Kyslyy on 6/10/18.
//

#ifndef PISCINE_CPP_SUPERTRAP_HPP
#define PISCINE_CPP_SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
    SuperTrap(void);
    SuperTrap(std::string const name);
    SuperTrap(SuperTrap const & src);

    SuperTrap   &operator=(SuperTrap const & src);
};

#endif //PISCINE_CPP_SUPERTRAP_HPP
