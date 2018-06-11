#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{}

PowerFist::PowerFist(std::string name, int apcost, int damage) :
        AWeapon(name, apcost, damage)
{}

PowerFist::PowerFist(PowerFist const &src) : AWeapon("Power Fist", 8, 50)
{
    *this = src;
}

PowerFist& PowerFist::operator=(PowerFist const &src)
{
    AWeapon::operator=(src);
    return *this;
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *\n";
}