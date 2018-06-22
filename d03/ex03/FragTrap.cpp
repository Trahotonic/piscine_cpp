#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Default FragTrap created\n";
}

FragTrap::FragTrap(std::string const name)
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
