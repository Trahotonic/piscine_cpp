//
// Created by Roman Kyslyy on 6/16/18.
//

#ifndef GIT_CPP_STRIPMINER_HPP
#define GIT_CPP_STRIPMINER_HPP

#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{
public:
    StripMiner(void);
    StripMiner(StripMiner const & src);

    StripMiner  &operator=(StripMiner const & src);

    ~StripMiner(void);

    void mine(IAsteroid *);
};

#endif //GIT_CPP_STRIPMINER_HPP
