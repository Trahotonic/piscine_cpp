#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <random>

class	ScavTrap
{
private:
	int		_hitPoints;
	int		_maxHitPoints;
	int		_energyPoints;
	int		_maxEnergyPoints;
	int		_level;
	std::string	_name;
	int		_meleeAttackDamage;
	int		_rangedAttackDamage;
	int		_armorDamageReduction;
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);

	ScavTrap	&operator=(ScavTrap const & src);

	~ScavTrap(void);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(std::string const & newcomer);

	void	displayInfo(void);

	int 	getHP(void) const;
	int 	getMHP(void) const;
	int 	getEP(void) const;
	int 	getMEP(void) const;
	int 	getLVL(void) const;
	std::string 	getName(void) const;
	int 	getMAT(void) const;
	int 	getRAT(void) const;
	int 	getADR(void) const;
};

#endif

