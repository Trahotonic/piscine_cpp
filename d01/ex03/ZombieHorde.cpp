#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int nb)
{
    this->horde = new Zombie[nb];
    this->horde_size = nb;
    std::cout << "Horde created\n";
}

ZombieHorde::~ZombieHorde(void)
{
    delete [] this->horde;
    std::cout << "Horde destroyed\n";
}

void ZombieHorde::announce(void)
{
    int n;

    n = 0;
    while (n < this->horde_size)
    {
        horde[n].announce();
        n += 1;
    }
}
