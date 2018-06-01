//
// Created by Roman KYSLYY on 6/1/18.
//

#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP

#include "Weapon.class.hpp"

class   HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);

	void    attack(void);

private:
	const std::string   _name;
	Weapon              &weaponRef;
};

#endif //CPP_HUMANA_HPP
