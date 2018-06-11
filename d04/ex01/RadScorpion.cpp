#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *\n";
}

RadScorpion::~RadScorpion(void)
{
    std::cout << "* SPROTCH *\n";
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(int hp, const std::string &type) : Enemy(hp, type)
{
    std::cout << "* SPROTCH *\n";
}
