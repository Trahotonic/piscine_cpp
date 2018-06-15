//
// Created by Roman KYSLYY on 6/14/18.
//

#include "Character.hpp"

Character::Character(void) : _name("default")
{}

Character::Character(Character const &src)
{
    *this = src;
}

Character::Character(std::string const &name) : _name(name)
{}

Character& Character::operator=(Character const &src)
{
    if (this != &src)
    {
        this->_name = src.getName();
        int n = 0;
        while (n < 4)
        {
            if (this->inventory[n])
                delete this->inventory[n];
            n++;
        }
        n = 0;
        while (n < 4)
        {
            this->inventory[n] = src.inventory[n]->clone();
            n++;
        }
    }
    return *this;
}

Character::~Character()
{}

std::string const& Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    int n = 0;

    while (n < 4)
    {
        if (!this->inventory[n])
        {
            this->inventory[n] = m;
            break ;
        }
        n++;
    }
}

void Character::unequip(int idx)
{
    if (this->inventory[idx])
    {
        delete this->inventory[idx];
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 4 && this->inventory[idx])
    {
        this->inventory[idx]->use(target);
    }
}
