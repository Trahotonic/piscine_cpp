//
// Created by Roman Kyslyy on 6/16/18.
//

#ifndef GIT_CPP_DEEPCOREMINER_HPP
#define GIT_CPP_DEEPCOREMINER_HPP

#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
public:
    DeepCoreMiner(void);
    DeepCoreMiner(DeepCoreMiner const & src);

    DeepCoreMiner   &operator=(DeepCoreMiner const & src);

    ~DeepCoreMiner(void);

    void mine(IAsteroid *);
};

#endif //GIT_CPP_DEEPCOREMINER_HPP