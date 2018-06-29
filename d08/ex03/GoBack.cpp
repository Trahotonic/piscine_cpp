//
// Created by Roman KYSLYY on 6/29/18.
//

#include "GoBack.hpp"

GoBack::GoBack()
{
	_pair = 1;
}

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

void GoBack::execute(int array[], int & index, int & comIndex, std::vector<AInstruction*> vec)
{
	if (array[index] != 0)
	{
		int balance = 0;
		while (comIndex >= 0)
		{
			if (vec[comIndex]->getPair() == 1)
				balance++;
			if (vec[comIndex]->getPair() == 2)
				balance--;
			if (vec[comIndex]->getPair() == 2 && !balance)
				break ;
			comIndex--;
		}
		if (comIndex < 0)
			comIndex++;
	}
	comIndex++;
}
