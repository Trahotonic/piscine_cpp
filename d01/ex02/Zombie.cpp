#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << "<" << this->_name << ">" << " ("
              << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
    this->announce();
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " destroyed\n";
    return ;
}
