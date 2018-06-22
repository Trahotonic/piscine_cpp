#include "FragTrap.hpp"

int	main(void)
{
	FragTrap &johnny = *new FragTrap("Johnny");

	johnny.takeDamage(50);
	johnny.displayInfo();
	johnny.vaulthunter_dot_exe("Bocal");
	johnny.vaulthunter_dot_exe("Haters");
	johnny.vaulthunter_dot_exe("Russians");
	johnny.vaulthunter_dot_exe("Feminists");
	johnny.vaulthunter_dot_exe("LP");
	std::cout << "Battle is finished\n";
	if (johnny.getHP() != 0)
		delete &johnny;
	return (0);
}
