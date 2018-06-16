//
// Created by Roman Kyslyy on 6/16/18.
//

#ifndef GIT_CPP_MININGBARGE_HPP
#define GIT_CPP_MININGBARGE_HPP

#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"

class MiningBarge
{
private:
    IMiningLaser *curLaser[4];
public:
    MiningBarge(void);
    MiningBarge(MiningBarge const & src);

    MiningBarge &operator=(MiningBarge const & src);

    ~MiningBarge(void);

    void    equip(IMiningLaser*);
    void    mine(IAsteroid*) const;
};


#endif //GIT_CPP_MININGBARGE_HPP
