#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <random>

class	FragTrap
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

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);

	FragTrap	&operator=(FragTrap const & src);

	~FragTrap(void);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);

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
