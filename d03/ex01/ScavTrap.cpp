#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_name = name;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;

	srand(time(0));
	std::string const greetings[] = {
	"\"Hello there!\"\n",
	"\"Greetings!\"\n",
	"\"Nice to meet you!\"\n"
	};
	std::cout << "ScavTrap " << name << ": " << greetings[rand() % 3];
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const & src)
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

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destroyed\n";
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name
			<< " is dead and cannot attack\n";
		return ;
	}
	std::cout << "ScavTrap " << this->_name
		<< "attacks " << target << " at range, causing "
		<< this->_rangedAttackDamage << " points of damage!\n";
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name
			<< " is dead and cannot attack\n";
		return ;
	}

	std::cout << "ScavTrap " << this->_name
		<< "attacks " << target << " in close combat, causing "
		<< this->_meleeAttackDamage << " points of damage!\n";

}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap	" << this->_name
			<< " is already dead\n";
		return ;
	}

	if ((int)amount < this->_armorDamageReduction)
		amount = 0;
	else
		amount -= this->_armorDamageReduction;
	if ((int)amount > this->_hitPoints)
		amount = this->_hitPoints;

	std::cout << "ScavTrap " << this->_name
		<< " is attacked by enemies and \e[31mloses "
		<< amount << " HP!\e[0m\n";
	this->_hitPoints -= amount;
	if (this->_hitPoints == 0)
	{
		delete (this);
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name
			<< " is already dead and cannot be repaired\n";
		return ;
	}
	if ((int)amount + this->_hitPoints + this->_maxHitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;

	std::cout << "ScavTrap " << this->_name
		<< " gets repaired and \e[92mrestores "
		<< amount << " HP!\e[0m\n";
	this->_hitPoints += amount;
}

void	ScavTrap::challengeNewcomer(std::string const & newcomer)
{
	std::string const challenges[] = {
	"You have to make me a peanut butter sandwich using only your mind",
	"You need to divide by zero",
	"Touch yourself while riding a bicycle",
	"Never give me up",
	"Buy me icecream",
	"Give me a reason to live",
	"Take me to the moon",
	"Sleep for next 10 hours"
	};

	if (this->_energyPoints < 25)
	{
		std::cout << "ScavTrap " << this->_name
				<< " cannot perform any special attacks due to a lack of energy\n";
		return ;
	}
	std::cout << "ScavTrap " << this->_name
			<< ": \"Hey " << newcomer << "! \e[93m" << challenges[rand() % 8] << "\e[0m.\"\n";
	this->_energyPoints -= 25;
}

