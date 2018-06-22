#include "Zombie.hpp"
#include "ZombieEvent.hpp"

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
	random->announce();
    delete random;
}

int main(void)
{
    Zombie firstZombie ("Sponge Bob", "Leader");

    ZombieEvent event;
    event.setZombieType("Shaman");
    Zombie *secondZombie = event.newZombie("Patrick");
    randomChump();
	delete secondZombie;
    return (0);
}
