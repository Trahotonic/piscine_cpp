//
// Created by Roman KYSLYY on 6/29/18.
//

#include "NextBox.hpp"

NextBox::NextBox()
{
	_pair = 0;
}

NextBox::NextBox(NextBox const &src)
{
	*this = src;
}

NextBox& NextBox::operator=(NextBox const &src)
{
	(void)src;
	return *this;
}

NextBox::~NextBox()
{}

void NextBox::execute(int array[], int & index, int & comIndex, std::vector<AInstruction*> vec)
{
	(void)array;
	(void)vec;
	index++;
	comIndex++;
}