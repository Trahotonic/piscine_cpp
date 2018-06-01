#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), weaponRef(weapon)
{
}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with his "
	          << weaponRef.getType() << std::endl;
}
