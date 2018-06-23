//
// Created by Roman KYSLYY on 6/23/18.
//

#ifndef GIT_CPP_SHOT_CLASS_HPP
#define GIT_CPP_SHOT_CLASS_HPP

#include "Ship.class.hpp"
#include <ncurses.h>

class Shot;

typedef struct	s_shots
{
	Shot			*shot;
	struct s_shots	*next;
};

class Shot
{
private:
	int _x;
	int _y;
public:
	Shot(void);
	Shot(Shot const & src);

	Shot(Ship const & src);

	Shot	&operator=(Shot const & src);

	~Shot(void);

	int 	getX(void);
	int 	getY(void);
	void	setX(int);
	void	setY(int);
};

#endif //GIT_CPP_SHOT_CLASS_HPP
