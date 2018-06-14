//
// Created by Roman KYSLYY on 6/11/18.
//

#include "AssaultTerminator.hpp"

AssauntTerminator::AssauntTerminator(void)
{
	std::cout << "* teleports from space *\n";
}

AssauntTerminator::~AssauntTerminator(void)
{
	std::cout << "I`ll be back\n";
}

AssauntTerminator::AssauntTerminator(AssauntTerminator const &src)
{
	*this = src;
}

AssauntTerminator& AssauntTerminator::operator=(AssauntTerminator const &src)
{
	(void)src;
	return *this;
}

ISpaceMarine* AssauntTerminator::clone(void) const
{
	ISpaceMarine *newMarine = new AssauntTerminator(*this);
	return newMarine;
}

void AssauntTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *\n";
}

void AssauntTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *\n";
}

void AssauntTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT !\n";
}
