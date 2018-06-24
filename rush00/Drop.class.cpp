//
// Created by Roman Kyslyy on 6/18/18.
//

#include <ncurses.h>
#include <cstdlib>
#include "Drop.class.hpp"
#include "Ship.class.hpp"
#include "Shot.class.hpp"

Drop::Drop() : _color(0), _coolDown(20)
{
	_x = 0;
	_y = 0;
    Drop::_totalDrops++;
}

Drop::Drop(int maxX)
{
    Drop::_totalDrops++;

    _x = maxX - 3;
	_y = (getmaxy(stdscr) / 4 + 2) + (rand() % ((getmaxy(stdscr) / 2) - 4));
    if (_y < 2)
        _y = 2;
    _color = (rand() % 4) + 2;
 }

Drop::Drop(Drop const &src)
{
    Drop::_totalDrops++;
    *this = src;
}

Drop& Drop::operator=(Drop const &src)
{
    Drop::_totalDrops++;
    this->_x = src.getX();
    this->_y = src.getY();
    return *this;
}

Drop::~Drop(void)
{
    Drop::_totalDrops--;
}

int Drop::getColor() const
{
    return _color;
}

int Drop::getTotalDrops() const
{
    return _totalDrops;
}

int Drop::getCoolDown()
{
	return _coolDown;
}

void Drop::setColor(int color)
{
    _color = color;
}

void Drop::setCoolDown(int n)
{
	_coolDown = n;
}

void    decrementX(t_drops ** drops, t_shots ** shots, Ship & ship, Ship * ship2)
{
	int n;
	if (!*drops)
		return ;
    for (t_drops *ptr = *drops; ptr ; ptr = ptr->next)
	{
		n = rand() % 3000;
		if (ptr->drop->getCoolDown() <= 0 && n >= 2000 && n <= 2200)
		{
			ptr->drop->setCoolDown(20);
			ptr->drop->shoot(shots);
		}
		ptr->drop->setCoolDown(ptr->drop->getCoolDown() - 1);
		if (ptr->drop->getX() >= 0)
			ptr->drop->setX(ptr->drop->getX() - 1);
		if (ship.get_hitPoints())
		{
			if ((ptr->drop->getX() <= ship.getX() + 3
				 && ptr->drop->getY() == ship.getY()) ||
				(ptr->drop->getX() <= ship.getX() + 2
				 && ptr->drop->getY() == ship.getY() - 1) ||
				(ptr->drop->getX() <= ship.getX() + 2
				 && ptr->drop->getY() == ship.getY() + 1))
			{
				ship.set_health(ship.get_hitPoints() - 1);
				if (ptr == *drops)
				{
					t_drops *tmp = ptr;
					*drops = ptr->next;
					delete tmp->drop;
					delete tmp;
				}
				else
				{
					for (t_drops *ptr2 = *drops; ptr2->next != ptr; ptr = ptr->next)
					{
						t_drops *del = ptr2->next;
						ptr2->next = ptr2->next->next;
						delete del->drop;
						delete del;
					}
				}
				if (!ship2)
					continue;
			}
		}
		if (ship2)
		{
			if ((ptr->drop->getX() <= ship2->getX() + 3
				 && ptr->drop->getY() == ship2->getY()) ||
				(ptr->drop->getX() <= ship2->getX() + 2
				 && ptr->drop->getY() == ship2->getY() - 1) ||
				(ptr->drop->getX() <= ship2->getX() + 2
				 && ptr->drop->getY() == ship2->getY() + 1))
			{
				ship2->set_health(ship2->get_hitPoints() - 1);
				if (ptr == *drops)
				{
					t_drops *tmp = ptr;
					*drops = ptr->next;
					delete tmp->drop;
					delete tmp;
				}
				else
				{
					for (t_drops *ptr2 = *drops; ptr2->next != ptr; ptr = ptr->next)
					{
						t_drops *del = ptr2->next;
						ptr2->next = ptr2->next->next;
						delete del->drop;
						delete del;
					}
				}
				continue;
			}
		}
	}
}

void    makeFresh(t_drops ** drops, int maxX, int maxY,
				  unsigned char i, unsigned char *timeout)
{
	(void)maxY;
	t_drops *tmp;
	maxX = getmaxx(stdscr);
	maxY = getmaxy(stdscr);
	if (!*drops)
	{
		*drops = new t_drops;
		tmp = *drops;
		tmp->drop = new Drop(getmaxx(stdscr));
		tmp->next = NULL;
		return ;
	}
	if (i % 20 == 0 && *timeout <= 0)
	{
		tmp = *drops;
		if (!tmp)
		{
			tmp = new t_drops;
			tmp->drop = new Drop(getmaxx(stdscr));
			tmp->next = NULL;
		}
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new t_drops;
		tmp->next->drop = new Drop(getmaxx(stdscr));
		tmp->next->next = NULL;
	}
    for (t_drops *ptr = *drops; ptr; ptr = ptr->next)
    {
		if (ptr->drop->getX() <= 0)
		{
			if (ptr == *drops)
			{
				t_drops *tmp = ptr;
				*drops = ptr->next;
				delete tmp->drop;
				delete tmp;
			}
			else
			{
				for (t_drops *ptr2 = *drops; ptr2->next != ptr; ptr = ptr->next)
				{
					t_drops *del = ptr2->next;
					ptr2->next = ptr2->next->next;
					delete del->drop;
					delete del;
				}
			}
		}
    }

}

void Drop::shoot(t_shots **shots)
{
	t_shots *buff = *shots;
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
	system("afplay -v 0.5 ./sounds/shoot_sound.mp3 &");
}

int Drop::_totalDrops = 0;