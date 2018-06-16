//
// Created by Roman Kyslyy on 6/16/18.
//

#ifndef GIT_CPP_IASTEROID_HPP
#define GIT_CPP_IASTEROID_HPP

#include <iostream>

#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

class IAsteroid
{
public:
    virtual ~IAsteroid(void) {}
    virtual std::string beMined(StripMiner *) const = 0;
    virtual std::string beMined(DeepCoreMiner *) const = 0;
    virtual std::string getName(void) const = 0;
};

#endif //GIT_CPP_IASTEROID_HPP
