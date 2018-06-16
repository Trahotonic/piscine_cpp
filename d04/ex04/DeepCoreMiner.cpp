//
// Created by Roman Kyslyy on 6/16/18.
//

#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"

DeepCoreMiner::DeepCoreMiner()
{}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &src)
{
    *this = src;
}

DeepCoreMiner& DeepCoreMiner::operator=(DeepCoreMiner const &src)
{
    (void)src;
    return *this;
}

DeepCoreMiner::~DeepCoreMiner()
{}

void DeepCoreMiner::mine(IAsteroid * target)
{
    std::cout << "* mining deep ... got " << target->beMined(this) << " *\n";
}
