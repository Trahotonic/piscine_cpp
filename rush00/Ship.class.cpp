//
// Created by Roman KYSLYY on 6/23/18.
//

#include <sstream>
#include "Ship.class.hpp"
#include "Shot.class.hpp"

Ship::Ship() : _hitPoints(25), _score(0)
{
	_x = 0;
	_y = getmaxy(stdscr) / 2;
}

Ship::Ship(Ship const &src)
{
	*this = src;
}

Ship::Ship(int y) : _hitPoints(25), _score(0)
{
	_y = y;
	_x = 0;
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

void Ship::shoot(t_shots **shots)
{
	t_shots *buff = *shots;
	if (_hitPoints <= 0)
		return ;
	if (!*shots)
	{
		*shots = new t_shots;
		t_shots *buff = *shots;
		buff->shot = new Shot(*this);
		buff->next = NULL;
		*shots = buff;
	}
	else if (!buff->shot)
	{
		buff->shot = new Shot(*this);
		buff->next = NULL;
	}
	else
	{
		t_shots *buff = *shots;

		while (buff->next)
			buff = buff->next;

		buff->next = new t_shots;
		buff->next->shot = new Shot(*this);
		buff->next->next = NULL;
	}
	system("afplay -v 0.5 ./sounds/sfx_wpn_laser6.wav &");
}

int Ship::get_score() const {
	return this->_score;
}

void Ship::set_score(int score) {
	this->_score = score;
}

std::string Ship::get_str_score() const {
	std::stringstream out;
	out << this->get_score();
	std::string s = "Score: " + out.str();
	return s;
}

int Ship::get_hitPoints() const {
	return this->_hitPoints;
}

std::string Ship::get_str_hit_points() const {
	std::stringstream out;
	out << this->get_hitPoints();
	std::string s = "Remaining health: " + out.str();
	return s;
}
void Ship::set_health(int health) {
	this->_hitPoints = health;
}
