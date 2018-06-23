//
// Created by Roman KYSLYY on 6/23/18.
//

#include "Ship.class.hpp"

Ship::Ship() : _hitPoints(100), _x(0), _y(getmaxy(stdscr) / 2)
{}

Ship::Ship(Ship const &src)
{
	*this = src;
}

Ship& Ship::operator=(Ship const &src)
{
	_hitPoints = src._hitPoints;
	_x = src._x;
	_y = src._y;
	return *this;
}

Ship::~Ship()
{}


int Ship::getX(void) const
{
	return _x;
}

int Ship::getY(void) const
{
	return _y;
}

void Ship::setX(int newX)
{
	_x = newX;
}

void Ship::setY(int newY)
{
	_y = newY;
}

Ship Ship::operator++()
{
	_y++;
	return *this;
}

Ship Ship::operator--()
{
	_y--;
	return *this;
}