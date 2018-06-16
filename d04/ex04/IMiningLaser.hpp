//
// Created by Roman Kyslyy on 6/16/18.
//

#ifndef GIT_CPP_IMININGLASER_HPP
#define GIT_CPP_IMININGLASER_HPP

#include <iostream>

class IAsteroid;

class IMiningLaser
{
public:
    virtual         ~IMiningLaser(void) {}
    virtual void    mine(IAsteroid*) = 0;
};

#endif //GIT_CPP_IMININGLASER_HPP
