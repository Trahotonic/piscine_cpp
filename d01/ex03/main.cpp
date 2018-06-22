#include <iostream>
#include <random>
#include "ZombieHorde.hpp"

int main(void)
{
    std::srand(time(0));
    ZombieHorde *horde = new ZombieHorde(50);
    horde->announce();
    delete horde;
    return (0);
}