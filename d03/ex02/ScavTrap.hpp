#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <random>

class	ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string const & name);
	ScavTrap(ScavTrap const & src);

	ScavTrap	&operator=(ScavTrap const & src);

	~ScavTrap(void);

	void	challengeNewcomer(std::string const & newcomer);
};

#endif

