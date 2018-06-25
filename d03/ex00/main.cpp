#include "FragTrap.hpp"

int	main(void)
{
		FragTrap &johnny = *new FragTrap("John");
	johnny.meleeAttack("test");
	return (0);
}
