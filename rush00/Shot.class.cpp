//
// Created by Roman KYSLYY on 6/23/18.
//

#include "Shot.class.hpp"
#include "Ship.class.hpp"
#include "Drop.class.hpp"

Shot::Shot(void)
{
	_x = 1;
	_y = getmaxy(stdscr);
}

Shot::Shot(Shot const &src)
{
	*this = src;
}

Shot::Shot(Ship const &src)
{
	_x = 5;
	_y = src.getY();
}

Shot::Shot(Drop const &src)
{
	_x = src.getX() - 1;
	_y = src.getY();
}

Shot& Shot::operator=(Shot const &src)
{
	_x = src._x;
	_y = src._y;
	return *this;
}

Shot::~Shot()
{
}

void	refreshShots(t_shots **shots)
{
	t_shots	*check = *shots;
	if (!check || !check->shot)
		return ;
	for (t_shots *ptr = *shots; ptr; ptr = ptr->next)
		ptr->shot->setX(ptr->shot->getX() + 1);
	for (t_shots *ptr = *shots; ptr; ptr = ptr->next)
	{
		if (ptr->shot->getX() == getmaxx(stdscr))
		{
			if (ptr == *shots)
			{
				t_shots *tmp = ptr;
				*shots = ptr->next;
				delete tmp->shot;
				delete tmp;
				return ;
			}
			else
			{
				t_shots *ptr2 = *shots;
				while (ptr2->next != ptr && ptr2->next)
					ptr2 = ptr2->next;
				t_shots *del = ptr2->next;
				if (ptr2->next->next)
					ptr2->next = ptr2->next->next;
				else
					ptr2->next = NULL;
				delete del->shot;
				delete del;
				return ;
			}
		}
	}
}

void	refreshShotsBack(t_shots **shots, Ship & ship, bool multiplayer)
{
	t_shots	*check = *shots;
	if (!check || !check->shot)
		return ;
	if (!multiplayer)
		for (t_shots *ptr = *shots; ptr; ptr = ptr->next)
			ptr->shot->setX(ptr->shot->getX() - 2);
	for (t_shots *ptr = *shots; ptr; ptr = ptr->next)
	{
		if (ptr->shot->getX() <= 0)
		{
			if (ptr == *shots)
			{
				t_shots *tmp = ptr;
				*shots = ptr->next;
				delete tmp->shot;
				delete tmp;
				return ;
			}
			else
			{
				t_shots *ptr2 = *shots;
				while (ptr2->next != ptr && ptr2->next)
					ptr2 = ptr2->next;
				t_shots *del = ptr2->next;
				if (ptr2->next->next)
					ptr2->next = ptr2->next->next;
				else
					ptr2->next = NULL;
				delete del->shot;
				delete del;
				return ;
			}
		}
		if (ship.get_hitPoints())
		{
			if ((ptr->shot->getY() == ship.getY() &&
				 (ptr->shot->getX() <= ship.getX() + 3)) ||
				((ptr->shot->getY() == ship.getY() - 1 &&
				  (ptr->shot->getX() <= ship.getX() + 3))) ||
				(((ptr->shot->getY() == ship.getY() + 1 &&
				   (ptr->shot->getX() <= ship.getX() + 3)))))
			{
				ship.set_health(ship.get_hitPoints() - 1);
				if (ptr == *shots)
				{
					t_shots *tmp = ptr;
					*shots = ptr->next;
					delete tmp->shot;
					delete tmp;
					return ;
				}
				else
				{
					t_shots *ptr2 = *shots;
					while (ptr2->next != ptr && ptr2->next)
						ptr2 = ptr2->next;
					t_shots *del = ptr2->next;
					if (ptr2->next->next)
						ptr2->next = ptr2->next->next;
					else
						ptr2->next = NULL;
					delete del->shot;
					delete del;
					return ;
				}
			}
		}
	}
}

void	checkCollision(t_shots** shots, t_drops** drops, Ship & ship)
{
	t_shots *scheck = *shots;
	t_drops *dcheck = *drops;

	if (!scheck || !dcheck || !scheck->shot || !dcheck->drop)
		return ;
	for (t_shots *sptr = *shots; sptr; sptr = sptr->next)
	{
		for (t_drops *dptr = *drops; dptr; dptr = dptr->next)
		{
			if (sptr->shot->getX() >= dptr->drop->getX() &&
					sptr->shot->getY() == dptr->drop->getY())
			{
				ship.set_score(ship.get_score() + 1);
				if (sptr == *shots)
				{
					t_shots *tmp = sptr;
					*shots = sptr->next;
					delete tmp->shot;
					delete tmp;
				}
				else
				{
					t_shots *ptr2 = *shots;
					while (ptr2->next != sptr && ptr2->next)
						ptr2 = ptr2->next;
					t_shots *del = ptr2->next;
					if (ptr2->next->next)
						ptr2->next = ptr2->next->next;
					else
						ptr2->next = NULL;
					delete del->shot;
					delete del;
				}
				if (dptr == *drops)
				{
					t_drops *tmp = dptr;
					*drops = dptr->next;
					delete tmp->drop;
					delete tmp;
					return ;
				}
				else
				{
					t_drops *ptr2 = *drops;
					while (ptr2->next != dptr && ptr2->next)
						ptr2 = ptr2->next;
					t_drops *del = ptr2->next;
					if (ptr2->next->next)
						ptr2->next = ptr2->next->next;
					else
						ptr2->next = NULL;
					delete del->drop;
					delete del;
					return ;
				}
			}
		}
	}
}
