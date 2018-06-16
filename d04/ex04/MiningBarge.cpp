//
// Created by Roman Kyslyy on 6/16/18.
//

#include "MiningBarge.hpp"

MiningBarge::MiningBarge(void)
{
    int n = 0;
    while (n < 4)
    {
        this->curLaser[n] = NULL;
        n++;
    }
}

MiningBarge::MiningBarge(MiningBarge const &src)
{
    *this = src;
}

MiningBarge& MiningBarge::operator=(MiningBarge const &src)
{
    (void)src;
    return *this;
}

MiningBarge::~MiningBarge(void)
{}

void MiningBarge::equip(IMiningLaser *newLaser)
{
    int n = 0;

    while (n < 4)
    {
        if (!this->curLaser[n])
        {
            this->curLaser[n] = newLaser;
            return ;
        }
        n++;
    }
}

void MiningBarge::mine(IAsteroid *asteroid) const
{
    int n = 0;

    while (n < 4)
    {
        if (this->curLaser[n])
            this->curLaser[n]->mine(asteroid);
        n++;
    }
}
