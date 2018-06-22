#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
int	main(void)
{
	std::cout << std::endl;
	FragTrap &johnny = *new FragTrap("Johnny");

	johnny.takeDamage(30);
	johnny.displayInfo();
	johnny.beRepaired(30);
	johnny.displayInfo();
	johnny.takeDamage(10);
	johnny.displayInfo();
	johnny.beRepaired(55);
	johnny.displayInfo();
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

	std::cout << "Battle is finished\n";
	if (johnny.getHP() != 0)
		delete &johnny;
	if (bob.getHP() != 0)
		delete &bob;
	return (0);
}
