//
// Created by Roman Kyslyy on 6/10/18.
//

#ifndef PISCINE_CPP_POWERFIST_HPP
#define PISCINE_CPP_POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public virtual AWeapon
{
public:
    PowerFist(void);
    PowerFist(std::string name, int apcost, int damage);
    PowerFist(PowerFist const & src);

    ~PowerFist(void);

    PowerFist &operator=(PowerFist const & src);
    void        attack(void) const ;
};

#endif //PISCINE_CPP_POWERFIST_HPP
