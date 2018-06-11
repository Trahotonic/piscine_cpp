#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

void	displayInfo(ClapTrap const & src)
{
	if (src.getHitPoints() == 0)
	{
		std::cout << "FR4G-TP " << src.getName()
			<< " is dead\n";
		return ;
	}
	std::cout << "FR4G-TP " << src.getName()
		<< " (level " << src.getLevel() << ")"
		<< " has " << src.getHitPoints()
		<< "/" << src.getMaxHitPoints() << " HP\n";
}

int	main(void)
{
	std::cout << std::endl;
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

	NinjaTrap &satori = *new NinjaTrap("Satori");

	satori.ninjaShoebox(johnny);
	satori.ninjaShoebox(bob);

	SuperTrap clark("Clark");
	clark.vaulthunter_dot_exe("Bitch");
	clark.ninjaShoebox(johnny);
	displayInfo(johnny);
	clark.ninjaShoebox(johnny);
	displayInfo(johnny);

	std::cout << "Battle is finished\n";
	if (johnny.getHitPoints() != 0)
		delete &johnny;
	if (bob.getHitPoints() != 0)
		delete &bob;
	return (0);
}
