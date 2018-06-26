//
// Created by Roman KYSLYY on 6/11/18.
//

#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

void	runMarine(TacticalMarine  *src, std::string method)
{
	if (src == NULL)
	{
		std::cout << "Marine does not exist\n";
		return ;
	}
	if (method != "meleeAttack" && method != "rangedAttack" &&
			method != "battleCry")
	{
		std::cout << "No such method in marine\n";
		return ;
	}
	if (method == "meleeAttack")
		src->meleeAttack();
	else if (method == "rangedAttack")
		src->rangedAttack();
	else if (method == "battleCry")
		src->battleCry();
}

int main(void)
{
	TacticalMarine *bob = NULL;

	int n = 1;
	try
	{
		if (n % 2 == 0)
			throw "Bob cannot be created with such number\n";
		bob = new TacticalMarine();
	}
	catch (char const * e)
	{
		std::cout << e << std::endl;
	}
	runMarine(bob, "battlCry");
	return (0);
}