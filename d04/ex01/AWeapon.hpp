//
// Created by Roman Kyslyy on 6/10/18.
//

#ifndef PISCINE_CPP_AWEAPON_HPP
#define PISCINE_CPP_AWEAPON_HPP

# include <iostream>

class AWeapon
{
private:
    std::string _name;
    int         _damage;
    int         _apCost;

public:
    AWeapon(void);
    AWeapon(std::string const & name, int apcost, int damage);
    AWeapon(AWeapon const & src);

    AWeapon &operator=(AWeapon const & src);

    ~AWeapon(void);

    std::string getName(void) const;
    int         getAPCost(void) const;
    int         getDamage(void) const;

    virtual void        attack(void) const = 0;
};

#endif //PISCINE_CPP_AWEAPON_HPP
