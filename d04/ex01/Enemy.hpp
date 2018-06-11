#ifndef PISCINE_CPP_ENEMY_HPP
#define PISCINE_CPP_ENEMY_HPP

#include <iostream>

class Enemy
{
private:
    int         _HP;
    std::string _type;
public:
    Enemy(void);
    Enemy(int hp, std::string const & type);
    Enemy(Enemy const & src);

    ~Enemy(void);

    Enemy   &operator=(Enemy const & src);

    std::string getType() const;
    int         getHP() const ;

    virtual void takeDamage(int);
};

#endif //PISCINE_CPP_ENEMY_HPP
