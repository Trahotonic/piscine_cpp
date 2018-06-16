//
// Created by Roman Kyslyy on 6/16/18.
//

#include "StripMiner.hpp"
#include "IAsteroid.hpp"

StripMiner::StripMiner(void)
{}

StripMiner::StripMiner(StripMiner const &src)
{
    *this = src;
}

StripMiner& StripMiner::operator=(StripMiner const &src)
{
    (void)src;
    return *this;
}

StripMiner::~StripMiner(void)
{}

void StripMiner::mine(IAsteroid * target)
{
    std::cout << "* mining deep ... got " << target->beMined(this) << " *\n";
}
