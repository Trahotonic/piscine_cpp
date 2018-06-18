//
// Created by Roman Kyslyy on 5/31/18.
//

#include "Zombie.hpp"

class   ZombieHorde
{
public:
        ZombieHorde(int nb);
        ~ZombieHorde(void);

        void    announce(void);

private:
        Zombie  *horde;
        int     horde_size;
};

#ifndef PISCINE_CPP_ZOMBIEHORDE_HPP
#define PISCINE_CPP_ZOMBIEHORDE_HPP

#endif //PISCINE_CPP_ZOMBIEHORDE_HPP
