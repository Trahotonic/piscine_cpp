#include "AWeapon.hpp"

AWeapon::AWeapon(void) :
        _name("Default weapon"), _damage(0), _apCost(0)
{}

AWeapon::AWeapon(AWeapon const &src)
{
    *this = src;
}

AWeapon::AWeapon(const std::string &name, int apcost, int damage) :
        _name(name), _damage(damage), _apCost(apcost)
{
}

AWeapon::~AWeapon(void)
{}

AWeapon& AWeapon::operator=(AWeapon const &src)
{
    this->_name = src._name;
    this->_damage = src._damage;
    this->_apCost = src._apCost;
    return (*this);
}

std::string AWeapon::getName(void) const
{
	return this->_name;
}

int AWeapon::getDamage(void) const
{
	return this->_damage;
}

int AWeapon::getAPCost(void) const
{
	return this->_apCost;
}
