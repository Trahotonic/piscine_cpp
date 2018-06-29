//
// Created by Roman KYSLYY on 6/29/18.
//

#include "GoBack.hpp"

GoBack::GoBack()
{}

GoBack::GoBack(GoBack const &src)
{
	*this = src;
}

GoBack& GoBack::operator=(GoBack const &src)
{
	(void)src;
	return *this;
}

GoBack::~GoBack()
{}

void GoBack::execute(int array[], int & index)
{
	if (array[index])
	{
		int balance = 0;
		while (index >= 0)
		{
			if (array[index] == ']')
				balance++;
			if (array[index] == '[')
				balance--;
			if (array[index] == '[' && !balance)
				break ;
			index--;
		}
		if (index < 0)
			index++;
	}
}
