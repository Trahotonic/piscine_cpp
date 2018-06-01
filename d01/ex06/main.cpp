#include "Weapon.class.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("Spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Another club");
		bob.attack();
	}
	{
		Weapon club = Weapon("Spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Another club");
		jim.attack();
	}
	return (0);
}