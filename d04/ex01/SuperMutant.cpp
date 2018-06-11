#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !\n";
}

SuperMutant::~SuperMutant(void)
{
    std::cout << "Aaargh...\n";
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !\n";
}

SuperMutant::SuperMutant(int hp, const std::string &type) : Enemy(hp, type)
{
    std::cout << "Gaaah. Me want smash heads !\n";
}

void SuperMutant::takeDamage(int amount)
{
    Enemy::takeDamage(amount - 3);
}
