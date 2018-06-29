//
// Created by Roman KYSLYY on 6/29/18.
//

#include "GoFront.hpp"

GoFront::GoFront()
{}

GoFront::GoFront(GoFront const &src)
{
	*this = src;
}

GoFront& GoFront::operator=(GoFront const &src)
{
	(void)src;
	return *this;
}

GoFront::~GoFront()
{}

void GoFront::execute(int array[], int & index)
{
	if (!array[index])
	{
		int balance = 0;
		while (index < 30000)
		{
			if (array[index] == '[')
				balance++;
			if (array[index] == ']')
				balance--;
			if (array[index] == ']' && !balance)
				break ;
			index++;
		}
		if (index == 30000)
			index--;
	}
}
