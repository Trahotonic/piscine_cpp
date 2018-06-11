#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

int main(void)
{
	Character *zaz = new Character("zaz");

	std::cout << *zaz;

	Enemy *b = new RadScorpion();
	Enemy *s = new SuperMutant();

	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);

	zaz->attack(s);
	std::cout << *zaz;
	zaz->attack(s);
	std::cout << *zaz;
	zaz->attack(s);
	std::cout << *zaz;
	zaz->attack(s);
	std::cout << *zaz;
	zaz->attack(s);
	std::cout << *zaz;
    return (0);
}