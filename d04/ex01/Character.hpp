//
// Created by Roman Kyslyy on 6/10/18.
//

#ifndef PISCINE_CPP_CHARACTER_HPP
#define PISCINE_CPP_CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	std::string _name;
	int 		_AP;
	AWeapon		*_cur_wep;
public:
	Character(void);
	Character(std::string const & name);
	Character(Character const & src);

	~Character(void);

	Character	&operator=(Character const & src);

	void	recoverAP(void);
	void	equip(AWeapon*);
	void	attack(Enemy*);

	std::string	getName(void) const;
	AWeapon		*getWeapon(void) const;
	int 		getAP(void) const;
};

std::ostream &operator<<(std::ostream & o, Character const & src);

#endif //PISCINE_CPP_CHARACTER_HPP
