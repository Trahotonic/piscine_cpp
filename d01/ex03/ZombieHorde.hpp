#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP


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

#endif //PISCINE_CPP_ZOMBIEHORDE_HPP
