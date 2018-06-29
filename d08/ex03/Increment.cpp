//
// Created by Roman KYSLYY on 6/29/18.
//

#include "Increment.hpp"

Increment::Increment()
{}

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

void Increment::execute(int array[], int & index)
{
	array[index]++;
}