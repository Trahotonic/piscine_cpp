#include "Victim.hpp"

Victim::Victim() : _name("Default name")
{
    std::cout << "Some random victim called " << _name << " just popped !\n";
}

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << _name << " just popped !\n";
}

Victim::Victim(Victim const & src)
{
    *this = src;
}

Victim  &Victim::operator=(Victim const &src)
{
    this->_name = src.getName();
    return (*this);
}

Victim::~Victim(void)
{
    std::cout << "Victim " <<_name << " just died for no apparent reason !\n";
}

std::ostream    &operator<<(std::ostream & o, Victim & src)
{
    o << "I`m " << src.getName() << " and i like otters !\n";
    return (o);
}

std::string Victim::getName(void) const
{
    return _name;
}

void Victim::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into a cute little cheep !\n";
}
