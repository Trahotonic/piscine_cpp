//
// Created by Roman KYSLYY on 6/11/18.
//

#include "Squad.hpp"

Squad::Squad(void)
{
	this->unitCount = 0;
	this->marines = NULL;
}

int Squad::getCount(void) const
{
	return this->unitCount;
}

int Squad::push(ISpaceMarine *newMarine)
{
	if (!this->marines)
	{
		this->marines = new t_container;
		this->marines->marine = newMarine;
		this->marines->next = NULL;
	}
	else
	{
		t_container *ptr;
		ptr = this->marines;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new t_container;
		ptr->next->marine = newMarine;
		ptr->next->next = NULL;
	}
	this->unitCount++;
}

ISpaceMarine* Squad::getUnit(int index) const
{
	int			n;
	t_container	*ptr;

	n = 0;
	ptr = this->marines;
	while (ptr && n < index)
		n++;
	if (!ptr)
		return NULL;
	return ptr->marine;
}
