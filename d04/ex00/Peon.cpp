#include "Peon.hpp"

Peon::Peon(void)
{
    _name = "Default name";
    std::cout << "Zog zog\n";
}

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog\n";
}

Peon::Peon(Peon const &src)
{
    *this = src;
}

Peon& Peon::operator=(Peon const &src)
{
    this->_name = src.getName();
    return *this;
}

Peon::~Peon(void)
{
    std::cout << "Bleuark...\n";
}

void Peon::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into a pink pony !\n";
}
