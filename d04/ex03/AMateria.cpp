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

AMateria::AMateria(std::string const &type) : xp_(0), type_("default")
{
}

AMateria& AMateria::operator=(AMateria const &src)
{
    
}
