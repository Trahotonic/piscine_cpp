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
	ClapTrap(unsigned int hitPoints, unsigned int maxHitPoints, unsigned int energyPoints,
			 unsigned int maxEnergyPoints, unsigned int level, unsigned int meleeAttackDamage,
			 unsigned int rangedAttackDamage, unsigned int armorDamageReduction);
	ClapTrap(ClapTrap const & src);

	ClapTrap	&operator=(ClapTrap const & src);

	virtual ~ClapTrap(void);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getHitPoints(void) const;
	int		getMaxHitPoints(void) const;
	int		getEnergyPoints(void) const;
	int		getMaxEnergyPoints(void) const;
	int		getLevel(void) const;
	std::string	getName(void) const;
	int		getMeleeAttackDamage(void) const;
	int		getRangedAttackDamage(void) const;
	int		getArmorDamageReduction(void) const;
	void	setEnergyPoints(unsigned int points);
};

#endif

