//
// Created by Roman KYSLYY on 6/1/18.
//

#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

# include "Weapon.class.hpp"

class   HumanB
{
public:
	HumanB(std::string name);

	void    setWeapon(Weapon weapon);
	void    attack(void);

private:
	const std::string   _name;
	Weapon              *_weapon;
};

#endif //CPP_HUMANB_HPP
