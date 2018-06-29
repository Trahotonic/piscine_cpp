//
// Created by Roman KYSLYY on 6/29/18.
//

#include "Decrement.hpp"

Decrement::Decrement()
{
	_pair = 0;
}

Decrement::Decrement(Decrement const &src)
{
	*this = src;
}

Decrement& Decrement::operator=(Decrement const &src)
{
	(void)src;
	return *this;
}

Decrement::~Decrement()
{}

void Decrement::execute(int array[], int & index, int & comIndex, std::vector<AInstruction*> vec)
{
	(void)vec;
	array[index] -= 1;
	comIndex++;
}
