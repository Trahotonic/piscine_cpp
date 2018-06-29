//
// Created by Roman KYSLYY on 6/29/18.
//

#include "PrevBox.hpp"

PrevBox::PrevBox()
{}

PrevBox::PrevBox(PrevBox const &src)
{
	*this = src;
}

PrevBox& PrevBox::operator=(PrevBox const &src)
{
	(void)src;
	return *this;
}

PrevBox::~PrevBox()
{}

void PrevBox::execute(int array[], int & index)
{
	(void)array;
	index--;
}