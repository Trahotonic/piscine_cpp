//
// Created by Roman KYSLYY on 6/11/18.
//

#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main(void)
{
	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssauntTerminator;

	ISquad *vlc = new Squad;

	vlc->push(bob);
	vlc->push(jim);

	std::cout << std::endl;

	bob->battleCry();
	jim->battleCry();

	std::cout << std::endl;

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine *cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << std::endl;
	}
	delete vlc;

	return (0);
}