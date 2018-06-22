#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << name << ", " << title << ", is born !\n";
}

Sorcerer::Sorcerer(void) : _name("default name"), _title("default title")
{
    std::cout << _name << ", " << _title << ", is born !\n";
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
    *this = src;
}

Sorcerer& Sorcerer::operator=(Sorcerer const &src)
{
    this->_name = src.getName();
    this->_title = src.getTitle();
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Sorcerer &src)
{
    o << "I am " << src.getName() << ", " << src.getTitle() << ", and i like ponies !\n";
    return (o);
}

Sorcerer::~Sorcerer(void)
{
    std::cout << _name << ", " << _title << ", is dead! Consequences will never be the same !\n";
}

std::string Sorcerer::getName(void) const
{
    return _name;
}

std::string Sorcerer::getTitle(void) const
{
    return _title;
}

void Sorcerer::polymorph(Victim const & src)
{
    src.getPolymorphed();
}
