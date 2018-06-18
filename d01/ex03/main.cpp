#include <iostream>
#include <random>
#include <ctime>
#include "ZombieHorde.hpp"
#include "Zombie.hpp"

int main(void)
{
    std::srand(time(0));
    ZombieHorde *horde = new ZombieHorde(10);
    horde->announce();
    delete horde;
    return (0);
}