//
// Created by Roman KYSLYY on 6/29/18.
//

#include "GoFront.hpp"

GoFront::GoFront()
{
	_pair = 2;
}

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

void GoFront::execute(int array[], int & index, int & comIndex, std::vector<AInstruction*> vec)
{
	if (array[index] == 0)
	{
		int balance = 0;
		while (comIndex < 30000)
		{
			if (vec[comIndex]->getPair() == 2)
				balance++;
			if (vec[comIndex]->getPair() == 1)
				balance--;
			if (vec[comIndex]->getPair() == 1 && !balance)
				break ;
			comIndex++;
		}
		if (comIndex == 30000)
			comIndex--;
	}
	comIndex++;
}
