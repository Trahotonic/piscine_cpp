//
// Created by Roman KYSLYY on 6/29/18.
//

#include "NextBox.hpp"

NextBox::NextBox()
{}

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

void NextBox::execute(int array[], int & index)
{
	(void)array;
	index++;
}