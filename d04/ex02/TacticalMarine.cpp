//
// Created by Roman KYSLYY on 6/11/18.
//

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle\n";
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh\n";
}

ISpaceMarine* TacticalMarine::clone(void) const
{
	ISpaceMarine *ret = this;
	return ret;
}

void TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT\n";
}

void TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with chainsword *\n";
}

void TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with bolter *\n";
}

