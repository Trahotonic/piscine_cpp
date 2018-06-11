#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <random>
# include "ClapTrap.hpp"

class	FragTrap : public virtual ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string const name);
	FragTrap(FragTrap const & src);

	FragTrap	&operator=(FragTrap const & src);

	~FragTrap(void);

	void	vaulthunter_dot_exe(std::string const & target);
};

#endif
