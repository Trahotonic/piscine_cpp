#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

void HumanB::setWeapon(Weapon weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << _name << " attacks with his "
	          << _weapon->getType() << std::endl;
}
