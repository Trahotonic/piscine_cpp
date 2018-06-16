//
// Created by Roman Kyslyy on 6/16/18.
//

#ifndef GIT_CPP_KOALASTEROID_HPP
#define GIT_CPP_KOALASTEROID_HPP

#include "IAsteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

class BocalSteroid : public IAsteroid
{
private:
    std::string _name;
public:
    BocalSteroid(void);
    BocalSteroid(BocalSteroid const & src);

    BocalSteroid    &operator=(BocalSteroid const & src);

    ~BocalSteroid(void);

    std::string beMined(DeepCoreMiner *) const;
    std::string beMined(StripMiner *) const;

    std::string getName(void) const;
};

#endif //GIT_CPP_KOALASTEROID_HPP
