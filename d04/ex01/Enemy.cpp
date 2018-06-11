#include "Enemy.hpp"

Enemy::Enemy(void) : _HP(0), _type("Default")
{}

Enemy::Enemy(Enemy const &src)
{
    *this = src;
}

Enemy::Enemy(int hp, const std::string &type) : _HP(hp), _type(type)
{}

Enemy& Enemy::operator=(Enemy const &src)
{
    this->_type = src._type;
    this->_HP = src._HP;
    return *this;
}

Enemy::~Enemy(void)
{}

int Enemy::getHP(void) const
{
    return this->_HP;
}

std::string Enemy::getType(void) const
{
    return this->_type;
}

void Enemy::takeDamage(int amount)
{
	if (this->_HP == 0)
	{
		std::cout << this->_type << " is already dead\n";
		return ;
	}
    if (amount <= 0)
        return ;
    if (amount > this->getHP())
        amount = this->getHP();
    this->_HP -= amount;
    if (this->_HP == 0)
    {
		delete this;
    }
}
