//
// Created by Roman KYSLYY on 6/24/18.
//

#include "Base.class.hpp"

Base::Base(void) : _x(0), _y(0)
{}

Base::Base(Base const &src)
{
	*this = src;
}

Base& Base::operator=(Base const &src)
{
	_x = src._x;
	_y = src._y;
	return *this;
}

Base::~Base()
{}

int Base::getY() const
{
	return this->_y;
}

int Base::getX() const
{
	return this->_x;
}

void Base::setY(int y)
{
	this->_y = y;
}

void Base::setX(int x)
{
	this->_x = x;
}