//
// Created by Roman KYSLYY on 6/23/18.
//

#ifndef GIT_CPP_SHIP_CLASS_HPP
#define GIT_CPP_SHIP_CLASS_HPP

#include <ncurses.h>

class Ship
{
private:
	unsigned int	_hitPoints;
	int				_x;
	int				_y;
public:
	Ship(void);
	Ship(Ship const & src);

	Ship	&operator=(Ship const & src);

	~Ship(void);

	int 	getX(void) const;
	int 	getY(void) const;
	void	setX(int);
	void	setY(int);

	Ship    operator++(void);
	Ship    operator--(void);
};

#endif //GIT_CPP_SHIP_CLASS_HPP
