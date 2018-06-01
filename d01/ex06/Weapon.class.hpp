//
// Created by Roman KYSLYY on 6/1/18.
//

#ifndef CPP_WEAPON_CLASS_HPP
#define CPP_WEAPON_CLASS_HPP

# include <iostream>

class   Weapon
{
public:
	Weapon(std::string weapon);

	void        setType(std::string new_weapon);
	std::string &getType(void) const ;

private:
	std::string _type;
	std::string &_type_ref;
};

#endif //CPP_WEAPON_CLASS_HPP
