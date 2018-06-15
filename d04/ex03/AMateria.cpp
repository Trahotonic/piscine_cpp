//
// Created by Roman KYSLYY on 6/14/18.
//

#include "AMateria.hpp"

AMateria::AMateria(void) : xp_(0), type_("default")
{
}

AMateria::AMateria(AMateria const &src)
{
    *this = src;
}

AMateria::AMateria(std::string const &type) : xp_(0), type_(type)
{
}

AMateria::~AMateria()
{}

AMateria& AMateria::operator=(AMateria const &src)
{
    if (this != &src)
    {
        this->xp_ = src.getXP();
        this->type_ = src.getType();
    }
    return *this;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}

std::string	const& AMateria::getType() const
{
    return this->type_;
}

unsigned int AMateria::getXP() const
{
    return this->xp_;
}