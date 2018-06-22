#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
    std::cout << "Default NinjaTrap created\n";
}

NinjaTrap::NinjaTrap(const std::string name)
{
    _hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
    _name = name;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;

    srand(time(0));
    std::string const greetings[] = {
            "\"Enter the ninja!\"\n",
            "\"Time to slice some fruits!\"\n",
            "\"Have you ever seen samurai cop?\"\n"
    };
    std::cout << "NinjaTrap " << name << ": " << greetings[rand() % 3];
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
    *this = src;
}

NinjaTrap& NinjaTrap::operator=(NinjaTrap const & src)
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

    return *this;
}

void NinjaTrap::ninjaShoebox(FragTrap & src)
{
    if (this->_energyPoints < 30)
    {
        std::cout << "NinjaTrap " << this->_name
                  << " cannot perform any special actions due to a lack of energy\n";
        return ;
    }

    unsigned int damage = rand() % 60 + 15;
    std::cout << this->_name << " appeared behind " << src.getName()
              << " and struck him with a sword dealing " << damage << " damage!\n";
    src.takeDamage(damage);
    this->_energyPoints -= 30;
}

void NinjaTrap::ninjaShoebox(ScavTrap & src)
{
    if (this->_energyPoints < 25)
    {
        std::cout << "NinjaTrap " << this->_name
                  << " cannot perform any special actions due to a lack of energy\n";
        return ;
    }

    unsigned int steal = rand() % 5 + 10;
    if (steal > (unsigned int)src.getEnergyPoints())
        steal = src.getEnergyPoints();
    std::cout << this->_name << " appeared in front of " << src.getName()
              << " and stole " << steal << " energy from him!\n";
    src.setEnergyPoints(src.getEnergyPoints() - steal);
    this->_energyPoints -= 25;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &src)
{
    if (this == &src)
    {
        std::cout << "During meditation " << this->_name << " refilled 35 points of energy!";
    }
    else
    {
        int gain1 = 35;
        int gain2 = 35;
        if (gain1 + this->getEnergyPoints() > this->getMaxEnergyPoints())
            gain1 = this->getMaxEnergyPoints() - this->getEnergyPoints();
        if (gain2 + src.getEnergyPoints() > src.getMaxEnergyPoints())
            gain2 = src.getMaxEnergyPoints() - src.getEnergyPoints();
        std::cout << "During dual meditation " << this->getName()
                  << " and " << src.getName() << " refilled "
                  << gain1 << " and " << gain2 << " energy points respectively\n";
        this->setEnergyPoints(gain1);
        src.setEnergyPoints(gain2);
    }
}