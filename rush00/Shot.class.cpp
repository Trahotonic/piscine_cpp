//
// Created by Roman KYSLYY on 6/23/18.
//

#include "Shot.class.hpp"

Shot::Shot(void) : _x(1), _y(getmaxy(stdscr))
{
}

Shot::Shot(Shot const &src)
{
	*this = src;
}

Shot::Shot(Ship const &src) : _x(1), _y(src.getY())
{
}

Shot& Shot::operator=(Shot const &src)
{
	_x = src._x;
	_y = src._y;
	return *this;
}