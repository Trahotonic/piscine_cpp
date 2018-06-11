//
// Created by Roman Kyslyy on 6/10/18.
//

#ifndef PISCINE_CPP_RADSCORPION_HPP
#define PISCINE_CPP_RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public virtual Enemy
{
public:
    RadScorpion(void);
    RadScorpion(RadScorpion const & src);
    RadScorpion(int hp, std::string const & type);

    RadScorpion &operator=(RadScorpion const & src);

    ~RadScorpion(void);
};

#endif //PISCINE_CPP_RADSCORPION_HPP
