//
// Created by Roman Kyslyy on 6/16/18.
//

#ifndef GIT_CPP_ASTEROKREOG_HPP
#define GIT_CPP_ASTEROKREOG_HPP

#include "IAsteroid.hpp"

class AsteroBocal : public IAsteroid
{
private:
    std::string _name;
public:
    AsteroBocal(void);
    AsteroBocal(AsteroBocal const & src);

    AsteroBocal    &operator=(AsteroBocal const & src);

    ~AsteroBocal(void);

    std::string beMined(DeepCoreMiner *) const;
    std::string beMined(StripMiner *) const;

    std::string getName(void) const;

};

#endif //GIT_CPP_ASTEROKREOG_HPP
