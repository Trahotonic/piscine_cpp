//
// Created by Roman KYSLYY on 6/14/18.
//

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{}

Ice::Ice(Ice const &src)
{
    *this = src;
}

Ice::Ice(std::string const &type) : AMateria(type)
{}

Ice &Ice::operator=(Ice const &src)
{
    if (this != &src)
        AMateria::operator=(src);
    return *this;
}

Ice::~Ice()
{}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
