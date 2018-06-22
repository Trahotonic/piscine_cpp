#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : ClapTrap()
{
    std::cout << "Default SuperTrap created\n";
}

SuperTrap::SuperTrap(std::string const name) : ClapTrap()
{
    _hitPoints = 100;
    _maxHitPoints = 100;
    _energyPoints = 120;
    _maxEnergyPoints  = 120;
    _level = 1;
    _name = name;
    _meleeAttackDamage = 60;
    _rangedAttackDamage = 20;
    _armorDamageReduction = 5;

    srand(time(0));
    std::string const greetings[] = {
            "\"SuperTrap enters the building!\"\n",
            "\"Super means you`re already dead!\"\n",
            "\"It`s okay to be scared of me!\"\n"
    };
    std::cout << "SuperTrap " << name << ": " << greetings[rand() % 3];
}

SuperTrap::SuperTrap(SuperTrap const &src)
{
    *this = src;
}

SuperTrap& SuperTrap::operator=(SuperTrap const &src)
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