#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class	FragTrap
{
public:
	int		_hitPoints;
	int		_maxHitPoints;
	int		_energyPoints;
	int		_maxEnergyPoints;
	int		_level;
	std::string	_name;
	int		_meleeAttackDamage;
	int		_rangedAttackDamage;
	int		_armorDamageReduction;

	FragTrap(std::string name);
	FragTrap(FragTrap const & src);

	FragTrap	&operator=(FragTrap const & src);

	~FragTrap(void);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
