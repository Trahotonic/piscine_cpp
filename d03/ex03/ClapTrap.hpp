#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <random>

class	ClapTrap
{
protected:
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
	ClapTrap(void);
	ClapTrap(ClapTrap const & src);

	ClapTrap	&operator=(ClapTrap const & src);

	~ClapTrap(void);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	displayInfo(void);

	int		getHP(void) const;
	int		getMHP(void) const;
	int		getEP(void) const;
	int		getMEP(void) const;
	int		getLVL(void) const;
	std::string	getName(void) const;
	int		getMAD(void) const;
	int		getRAD(void) const;
	int		getADR(void) const;
	void	setEnergyPoints(unsigned int points);
};

#endif

