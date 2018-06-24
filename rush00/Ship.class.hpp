//
// Created by Roman KYSLYY on 6/23/18.
//

#ifndef GIT_CPP_SHIP_CLASS_HPP
#define GIT_CPP_SHIP_CLASS_HPP

#include <ncurses.h>
#include "Shot.class.hpp"

typedef struct s_shots t_shots;

class Ship : public Base
{
private:
	int	_hitPoints;
	int	_score;
public:
	Ship(void);
	Ship(Ship const & src);
	Ship(int y);

	Ship	&operator=(Ship const & src);

	~Ship(void);

	int get_score() const;
	int get_hitPoints() const;
	void	set_score(int score);
	void	set_health(int health);

	std::string get_str_hit_points() const;
	std::string	get_str_score() const;

	Ship    operator++(void);
	Ship    operator--(void);

	void	shoot(t_shots ** shots);
};

#endif //GIT_CPP_SHIP_CLASS_HPP
