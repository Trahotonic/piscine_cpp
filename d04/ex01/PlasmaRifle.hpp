#ifndef PISCINE_CPP_PLASMARIFLE_HPP
#define PISCINE_CPP_PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public virtual AWeapon
{
public:
    PlasmaRifle(void);
    PlasmaRifle(std::string name, int apcost, int damage);
    PlasmaRifle(PlasmaRifle const & src);

    ~PlasmaRifle(void);

    PlasmaRifle &operator=(PlasmaRifle const & src);
    void        attack(void) const ;
};

#endif //PISCINE_CPP_PLASMARIFLE_HPP
