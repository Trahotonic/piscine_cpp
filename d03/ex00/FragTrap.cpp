#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_hitPoints = 0;
	_maxHitPoints = 0;
	_energyPoints = 0;
	_maxEnergyPoints = 0;
	_level = 0;
	_name = "defaultName";
	_meleeAttackDamage = 0;
	_rangedAttackDamage = 0;
	_armorDamageReduction = 0;

	std::cout << "Hello. I am default FragTrap\n";
}

FragTrap::FragTrap(std::string name)
{
	if (name == "John")
        throw "John is bad";
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_name = name;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;

	srand(time(0));
	std::string const greetings[] = {
	"\"This time it'll be awesome, I promise!\"\n",
	"\"Let's get this party started!\"\n",
	"\"Look out everybody! Things are about to get awesome!\"\n"
	};
	std::cout << "FR4G-TP " << name << ": " << greetings[rand() % 3];
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
}

FragTrap	&FragTrap::operator=(FragTrap const & src)
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

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP " << this->_name << " destroyed\n";
}

void	FragTrap::rangedAttack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FR4G-TP " << this->_name
			<< " is dead and cannot attack\n";
		return ;
	}
	std::cout << "FR4G-TP " << this->_name
		<< "attacks " << target << " at range, causing "
		<< this->_rangedAttackDamage << " points of damage!\n";
}

void	FragTrap::meleeAttack(std::string const & target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FR4G-TP " << this->_name
			<< " is dead and cannot attack\n";
		return ;
	}

	std::cout << "FR4G-TP " << this->_name
		<< "attacks " << target << " in close combat, causing "
		<< this->_meleeAttackDamage << " points of damage!\n";

}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FR4G-TP " << this->_name
			<< " is already dead\n";
		return ;
	}

	if ((int)amount < this->_armorDamageReduction)
		amount = 0;
	else
		amount -= this->_armorDamageReduction;
	if ((int)amount > this->_hitPoints)
		amount = this->_hitPoints;

	std::cout << "FR4G-TP " << this->_name
		<< " is attacked by enemies and \e[31mloses "
		<< amount << " HP!\e[0m\n";
	this->_hitPoints -= amount;
	if (this->_hitPoints == 0)
	{
		delete (this);
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FR4G-TP " << this->_name
			<< " is already dead and cannot be repaired\n";
		return ;
	}
	if ((int)amount + this->_hitPoints + this->_maxHitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;

	std::cout << "FR4G-TP " << this->_name
		<< " gets repaired and \e[92mrestores "
		<< amount << " HP!\e[0m\n";
	this->_hitPoints += amount;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string const attacks[] = {
	"Oil fart",
	"Self explosion",
	"Dab to death",
	"Serious converstion about enviroment",
	"Game of Thrones spoilers",
	"Segmenation fault",
	"Hardcore guitar solo",
	"Pepe memes"
	};

	if (this->_energyPoints < 25)
	{
		std::cout << "FR4G-TP " << this->_name
				<< " cannot perform any special attacks due to a lack of energy\n";
		return ;
	}
	int index = rand() % 8;
	std::cout << "FR4G-TP " << this->_name
			<< " performs \e[93m" << attacks[index] << "\e[0m on "
			<< target << " and deals " << rand() % 30 + 45
			<< " damage\n";
	this->_energyPoints -= 25;
}

void	FragTrap::displayInfo(void)
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

int FragTrap::getHP() const
{
	return _hitPoints;
}

int FragTrap::getMHP() const
{
	return _maxHitPoints;
}

int FragTrap::getEP() const
{
	return _energyPoints;
}

int FragTrap::getMEP() const
{
	return _maxEnergyPoints;
}

int FragTrap::getLVL() const
{
	return _level;
}

std::string FragTrap::getName() const
{
	return _name;
}

int FragTrap::getMAT() const
{
	return _meleeAttackDamage;
}

int FragTrap::getRAT() const
{
	return _rangedAttackDamage;
}

int FragTrap::getADR() const
{
	return _armorDamageReduction;
}
