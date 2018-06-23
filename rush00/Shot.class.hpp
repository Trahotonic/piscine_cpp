//
// Created by Roman KYSLYY on 6/23/18.
//

#ifndef GIT_CPP_SHOT_CLASS_HPP
#define GIT_CPP_SHOT_CLASS_HPP

#include "Drop.class.hpp"
#include "Shot.class.hpp"
#include <ncurses.h>

class Shot;
class Ship;
class Drop;
typedef struct	s_shots
{
	Shot			*shot;
	struct s_shots	*next;
}				t_shots;
typedef struct	s_drops t_drops;
class Shot
{
private:
	int _x;
	int _y;
public:
	Shot(void);
	Shot(Shot const & src);

	Shot(Ship const & src);

	Shot(Drop const & src);

	Shot	&operator=(Shot const & src);

	~Shot(void);

	int 	getX(void);
	int 	getY(void);
	void	setX(int);
	void	setY(int);
};

void	refreshShots(t_shots **shots);
void	refreshShotsBack(t_shots **shots, Ship & ship);
void	checkCollision(t_shots**, t_drops **, Ship & ship);

#endif //GIT_CPP_SHOT_CLASS_HPP
