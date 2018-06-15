//
// Created by Roman KYSLYY on 6/14/18.
//

#include "Cure.hpp"

Cure::Cure(void) : AMateria::AMateria("cure")
{}

Cure::Cure(std::string const & type) : AMateria::AMateria(type)
{}

Cure::Cure(Cure const &src)
{
    *this = src;
}

Cure& Cure::operator=(Cure const &src)
{
    if (this != &src)
        AMateria::operator=(src);
    return *this;
}

Cure::~Cure()
{}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "`s woulds *\n";
}
