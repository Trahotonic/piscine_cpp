//
// Created by Roman Kyslyy on 6/10/18.
//

#ifndef PISCINE_CPP_NINJATRAP_HPP
#define PISCINE_CPP_NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
public:
    NinjaTrap(void);
    NinjaTrap(std::string const name);
    NinjaTrap(NinjaTrap const & src);

    NinjaTrap   &operator=(NinjaTrap const & src);

    void    ninjaShoebox(FragTrap & src);
    void    ninjaShoebox(ScavTrap & src);
    void    ninjaShoebox(NinjaTrap & src);
};

#endif //PISCINE_CPP_NINJATRAP_HPP
