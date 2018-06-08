#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	displayInfo(FragTrap const & src)
{
	if (src._hitPoints == 0)
	{
		std::cout << "FR4G-TP " << src._name
			<< " is dead\n";
		return ;
	}
	std::cout << "FR4G-TP " << src._name
		<< " (level " << src._level << ")"
		<< " has " << src._hitPoints
		<< "/" << src._maxHitPoints << " HP\n";
}

int	main(void)
{
	FragTrap &johnny = *new FragTrap("Johnny");

	johnny.takeDamage(30);
	displayInfo(johnny);
	johnny.beRepaired(30);
	displayInfo(johnny);
	johnny.takeDamage(10);
	displayInfo(johnny);
	johnny.beRepaired(55);
	displayInfo(johnny);
	johnny.vaulthunter_dot_exe("Bocal");
	johnny.vaulthunter_dot_exe("Haters");
	johnny.vaulthunter_dot_exe("Russians");
	johnny.vaulthunter_dot_exe("Feminists");
	johnny.vaulthunter_dot_exe("LP");

	ScavTrap &bob = *new ScavTrap("Bob");

	bob.challengeNewcomer("Punk ass bitch");
	std::cout << "Battle is finished\n";
	if (johnny._hitPoints != 0)
		delete &johnny;
	if (bob._hitPoints != 0)
		delete &bob;
	return (0);
}
