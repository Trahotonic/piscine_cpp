#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::string announcements[] = {
            "We are here gor your brains",
            "Time to feast",
            "Hey boss",
            "Hello there",
            "Braiiiiiiinnnssss...",
            "For the horde"
    };
    std::cout << "<" << this->_name << ">" << " ("
              << this->_type << ")> " << announcements[std::rand() % 6] << std::endl;
}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
    this->announce();
    return ;
}

Zombie::Zombie(void)
{
    std::string names[] = {
            "Roman",
            "Ivan",
            "Eugen",
            "Max",
            "Sasha",
            "Vadim"
    };
    std::string types[] = {
            "Scout",
            "Juggernaut",
            "Necromancer",
            "Berserk",
            "Commander",
            "Scavenger"
    };
    this->_name = names[std::rand() % 6];
    this->_type = types[std::rand() % 6];
    std::cout << "Zombie " << this->_name << " created\n";
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " destroyed\n";
    return ;
}
