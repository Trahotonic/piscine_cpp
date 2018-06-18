#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <ctime>

void    randomChump(void)
{
    std::cout << "Creating random zombie:\n";
    std::srand(time(0));
    int index;
    std::string names[] = {
            "Roman",
            "Ivan",
            "Eugen",
            "Max",
            "Sasha",
            "Vadim"
    };
    std::cout << "Random Zombie: ";
    index = std::rand() % 6;
    Zombie  *random = new Zombie(names[index], "Scout");
    delete random;
}

int main(void)
{
    Zombie first_zombie ("Sponge Bob", "Leader");

    ZombieEvent event;
    event.setZombieType("Joker");
    event.newZombie("Patrick");
    randomChump();
    return (0);
}
