//
// Created by Roman KYSLYY on 6/11/18.
//

#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main(void)
{
	ISquad *vlc = new Squad;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			TacticalMarine *bob = new TacticalMarine(i);
			vlc->push(bob);
		}
		else
		{
			std::cout << "Couldn't add new marine\n";
		}
	}
	return (0);
}