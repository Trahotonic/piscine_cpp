//
// Created by Roman KYSLYY on 6/29/18.
//

#include "Increment.hpp"

Increment::Increment()
{
	_pair = 0;
}

Increment::Increment(Increment const &src)
{
	*this = src;
}

Increment& Increment::operator=(Increment const &src)
{
	(void)src;
	return *this;
}

Increment::~Increment()
{}

void Increment::execute(int array[], int & index, int & comIndex, std::vector<AInstruction*> vec)
{
	(void)vec;
	array[index] += 1;
	comIndex++;
}