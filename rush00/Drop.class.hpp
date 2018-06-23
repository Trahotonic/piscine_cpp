//
// Created by Roman Kyslyy on 6/18/18.
//

#ifndef GIT_CPP_DROP_CLASS_HPP
#define GIT_CPP_DROP_CLASS_HPP

#include <time.h>
#include <iostream>
#include <random>
#include "Ship.class.hpp"


class Drop;
class Ship;

typedef struct		s_shots t_shots;

typedef struct      s_drops
{
    Drop            *drop;
    struct s_drops  *next;
}                   t_drops;

class Drop
{
private:
    int _y;
    int _x;
    int _color;
    static int _totalDrops;
	int _coolDown;
public:
    Drop(void);
    Drop(int maxX);
    Drop(Drop const & src);

    Drop    &operator=(Drop const & src);

    ~Drop(void);

    int     getX(void) const ;
    int     getY(void) const ;
    int     getColor(void) const;
    int     getTotalDrops(void) const;
	int 	getCoolDown(void);
    void    setX(int);
    void    setY(int);
    void    setColor(int);
	void	setCoolDown(int n);
	void	shoot(t_shots ** shots);
};

void    decrementX(t_drops*, t_shots**, Ship & ship);
void    makeFresh(t_drops**, int maxX, int maxY,
				  unsigned char i, unsigned char *timeout);

#endif //GIT_CPP_DROP_CLASS_HPP
