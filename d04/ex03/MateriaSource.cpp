//
// Created by Roman KYSLYY on 6/14/18.
//

#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *newMateria)
{
    int n = 0;

    while (n < 4 && this->materias[n] != 0)
        n++;
    if (n == 4)
        return ;
    materias[n] = newMateria;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    int n = 0;

    while (n < 4 && materias[n]->getType() != type)
        n++;
    if (materias[n]->getType() == type)
    {
        return (materias[n]->clone());
    }
    return NULL;
}