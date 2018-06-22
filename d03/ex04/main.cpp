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
	std::cout << std::endl;

	johnny.takeDamage(30);
	displayInfo(johnny);
	std::cout << std::endl;

	johnny.beRepaired(30);
	displayInfo(johnny);
	std::cout << std::endl;

	johnny.takeDamage(10);
	displayInfo(johnny);
	std::cout << std::endl;

	johnny.beRepaired(55);
	displayInfo(johnny);
	std::cout << std::endl;

	johnny.vaulthunter_dot_exe("Bocal");
	std::cout << std::endl;

	johnny.vaulthunter_dot_exe("Haters");
	std::cout << std::endl;

	johnny.vaulthunter_dot_exe("Russians");
	std::cout << std::endl;

	johnny.vaulthunter_dot_exe("Feminists");
	std::cout << std::endl;

	johnny.vaulthunter_dot_exe("LP");
	std::cout << std::endl;

	ScavTrap &bob = *new ScavTrap("Bob");
	std::cout << std::endl;

	bob.challengeNewcomer("Punk ass bitch");
	std::cout << std::endl;

	NinjaTrap &satori = *new NinjaTrap("Satori");
	std::cout << std::endl;

	satori.ninjaShoebox(johnny);
	std::cout << std::endl;
	satori.ninjaShoebox(bob);
	std::cout << std::endl;

	SuperTrap clark("Clark");
	std::cout << std::endl;

	clark.vaulthunter_dot_exe("Bitch");
	std::cout << std::endl;

	clark.ninjaShoebox(johnny);
	displayInfo(johnny);
	std::cout << std::endl;

	clark.ninjaShoebox(johnny);
	displayInfo(johnny);
	std::cout << std::endl;

	std::cout << "Battle is finished\n";
	if (johnny.getHitPoints() != 0)
		delete &johnny;
	if (bob.getHitPoints() != 0)
		delete &bob;
	return (0);
}
