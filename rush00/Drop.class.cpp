//
// Created by Roman Kyslyy on 6/18/18.
//

#include "Drop.class.hpp"

Drop::Drop() : _y(0), _x(0), _color(0)
{
    Drop::_totalDrops++;
}

Drop::Drop(int maxX, int maxY)
{
    Drop::_totalDrops++;
    srand(time(0));

    _x = maxX - 3;
    _y = rand() % maxY;
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

int Drop::getY() const
{
    return this->_y;
}

int Drop::getX() const
{
    return this->_x;
}

int Drop::getTotalDrops() const
{
    return _totalDrops;
}

void Drop::setY(int y)
{
    this->_y = y;
}

void Drop::setX(int x)
{
    this->_x = x;
}

void Drop::setColor(int color)
{
    _color = color;
}

void    decrementX(t_drops * drops)
{
    for (t_drops *ptr = drops; ptr ; ptr = ptr->next)
        ptr->drop->setX(ptr->drop->getX() - 1);
}

void    makeFresh(t_drops * drops, int maxX, int maxY, int maxDrops, unsigned char i, unsigned char *timeout)
{
    i = 0;
    for (t_drops *ptr = drops; ptr; ptr = ptr->next)
    {
        if (ptr->drop->getX() <= 0 && ptr->drop->getTotalDrops() > maxDrops)
        {
            if (ptr != drops)
            {
                t_drops *tmp = drops;
                while (tmp->next != ptr)
                    tmp = tmp->next;
                t_drops *tmp2 = tmp->next;
                tmp->next = tmp->next->next;
                delete tmp2->drop;
                delete tmp2;
            }
            return ;
        }
        if (ptr->drop->getX() == 0)
        {
            ptr->drop->setX(maxX - 3);
            ptr->drop->setY(rand() % maxY);
            if (ptr->drop->getY() < 2)
                ptr->drop->setY(2);
            ptr->drop->setColor(rand() % 5 + 1);
        }
        if (ptr->drop->getTotalDrops() < maxDrops && i % 20 == 0 && *timeout == 0)
        {
            t_drops *tmp = drops;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new t_drops;
            tmp->next->drop = new Drop(maxX, maxY);
            tmp->next->next = NULL;
            *timeout = 100;
        }
    }
}

int Drop::_totalDrops = 0;