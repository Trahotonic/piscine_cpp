#include "AWeapon.hpp"
#include "Character.hpp"

Character::Character(void) : _name("Default name"), _AP(40), _cur_wep(NULL)
{}

Character::Character(std::string const &name) : _name(name), _AP(40), _cur_wep(NULL)
{}

Character::Character(Character const &src)
{
	*this = src;
}

Character& Character::operator=(Character const &src)
{
	this->_name = src._name;
	this->_cur_wep = src._cur_wep;
	this->_AP = src._AP;
	return (*this);
}

std::string Character::getName() const
{
	return (this->_name);
}

AWeapon* Character::getWeapon(void) const
{
	return this->_cur_wep;
}

int Character::getAP(void) const
{
	return this->_AP;
}

void Character::recoverAP(void)
{
	this->_AP += 10;
}

void Character::equip(AWeapon *new_weapon)
{
	this->_cur_wep = new_weapon;
}

void Character::attack(Enemy *enemy)
{
	if (this->_AP < this->_cur_wep->getAPCost())
		return ;
	std::cout << this->_name << " attacks " << enemy->getType()
			  << " with a " << this->_cur_wep->getName() << std::endl;
	this->_AP -= this->_cur_wep->getAPCost();
	this->_cur_wep->attack();
	enemy->takeDamage(this->_cur_wep->getDamage());
}

std::ostream	&operator<<(std::ostream & o, Character const & src)
{
	if (src.getWeapon())
	{
		o << src.getName() << " has " << src.getAP()
		  << " AP and wields a " << src.getWeapon()->getName()
		  << std::endl;
	}
	else
	{
		o << src.getName() << " has " << src.getAP()
		  << " AP and is unarmed\n";
	}
	return (o);
}
