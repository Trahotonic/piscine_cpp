#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_name = name;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;

	std::cout << "Some ClapTrap named " << name << " is created\n";
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
	std::cout << this->_name << " destroyed\n";
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

