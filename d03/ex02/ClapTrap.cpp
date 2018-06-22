#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	_hitPoints = 0;
	_maxHitPoints = 0;
	_energyPoints = 0;
	_maxEnergyPoints = 0;
	_level = 0;
	_name = "default";
	_meleeAttackDamage = 0;
	_rangedAttackDamage = 0;
	_armorDamageReduction = 0;
	std::cout << "ClapTrap is created\n";
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const & src)
{
	this->_hitPoints = src._hitPoints;
	this->_maxHitPoints = src._maxHitPoints;
	this->_energyPoints = src._energyPoints;
	this->_maxEnergyPoints = src._maxEnergyPoints;
	this->_level = src._level;
	this->_name = src._name;
	this->_meleeAttackDamage = src._meleeAttackDamage;
	this->_rangedAttackDamage = src._rangedAttackDamage;
	this->_armorDamageReduction = src._armorDamageReduction;

	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " <<  this->_name << " destroyed\n";
}

void	ClapTrap::displayInfo(void)
{
	if (_hitPoints == 0)
	{
		std::cout << "FR4G-TP " << _name
				  << " is dead\n";
		return ;
	}
	std::cout << "FR4G-TP " << _name
			  << " (level " << _level << ")"
			  << " has " << _hitPoints
			  << "/" << _maxHitPoints << " HP\n";
}

int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

int ClapTrap::getMaxHitPoints(void) const
{
	return _maxHitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

int ClapTrap::getMaxEnergyPoints(void) const
{
	return _maxEnergyPoints;
}

int ClapTrap::getLevel(void) const
{
	return _level;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}

int ClapTrap::getMeleeAttackDamage(void) const
{
	return _meleeAttackDamage;
}

int ClapTrap::getRangedAttackDamage(void) const
{
	return _rangedAttackDamage;
}

int ClapTrap::getArmorDamageReduction(void) const
{
	return _armorDamageReduction;
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name
			<< " is dead and cannot attack\n";
		return ;
	}
	std::cout << this->_name
		<< "attacks " << target << " at range, causing "
		<< this->_rangedAttackDamage << " points of damage!\n";
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name
			<< " is dead and cannot attack\n";
		return ;
	}

	std::cout << this->_name
		<< "attacks " << target << " in close combat, causing "
		<< this->_meleeAttackDamage << " points of damage!\n";

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name
			<< " is already dead\n";
		return ;
	}

	if ((int)amount < this->_armorDamageReduction)
		amount = 0;
	else
		amount -= this->_armorDamageReduction;
	if ((int)amount > this->_hitPoints)
		amount = this->_hitPoints;

	std::cout << this->_name
		<< " is attacked by enemies and \e[31mloses "
		<< amount << " HP!\e[0m\n";
	this->_hitPoints -= amount;
	if (this->_hitPoints == 0)
	{
		delete (this);
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout <<  this->_name
			<< " is already dead and cannot be repaired\n";
		return ;
	}
	if ((int)amount + this->_hitPoints + this->_maxHitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;

	std::cout << this->_name
		<< " gets repaired and \e[92mrestores "
		<< amount << " HP!\e[0m\n";
	this->_hitPoints += amount;
}
