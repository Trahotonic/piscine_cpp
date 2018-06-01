#include "Weapon.class.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon), _type_ref(this->_type)
{
}

void Weapon::setType(std::string new_weapon)
{
	this->_type = new_weapon;
}

std::string & Weapon::getType(void) const
{
	return (_type_ref);
}
