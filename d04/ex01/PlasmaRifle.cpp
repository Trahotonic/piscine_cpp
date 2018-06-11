#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 21, 5)
{}

PlasmaRifle::PlasmaRifle(std::string name, int apcost, int damage) :
        AWeapon(name, apcost, damage)
{}

void PlasmaRifle::attack(void) const
{
    std::cout << "* piouuu piouuu piouuu *\n";
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon("Plasma Rifle", 21, 5)
{
    *this = src;
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const &src)
{
    AWeapon::operator=(src);
    return *this;
}
