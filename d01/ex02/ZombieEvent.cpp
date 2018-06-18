#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
    std::cout << "Zombie Event created" << std::endl;
}

ZombieEvent::~ZombieEvent(void)
{
    std::cout << "Zombie Event destroyed" << std::endl;
}

void ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
}

Zombie * ZombieEvent::newZombie(std::string name)
{
    Zombie *ret = new Zombie(name, this->_type);
    return (ret);
}
