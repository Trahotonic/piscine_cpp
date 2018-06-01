#include "Human.hpp"

void Human::meleeAttack(const std::string &target)
{
	std::cout << "This dude attacks " << target << " with his hands!\n";
}

void Human::rangedAttack(const std::string &target)
{
	std::cout << "This dude shoots " << target << " with his gun!\n";
}

void Human::intimidatingShout(const std::string &target)
{
	std::cout << "This dude screams towards " << target << ": 'Time to die!'\n";
}

void Human::action(const std::string &action_name, const std::string &target)
{
	std::string actions[] = {
			"meleeAttack",
			"rangedAttack",
			"intimidatingShout"
	};
	typedef void(Human::*acts)(const std::string &target);
	acts actionsList[] = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	int n = 0;
	while (n < 3)
	{
		if (action_name == actions[n])
			break ;
		n += 1;
	}
	if (n == 3)
	{
		std::cout << "Class Human does not contain method \"" << action_name << "\"\n";
		return ;
	}
	(this->*(actionsList[n]))(target);
}