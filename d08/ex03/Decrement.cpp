//
// Created by Roman KYSLYY on 6/29/18.
//

#include "Decrement.hpp"

Decrement::Decrement()
{}

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

void Decrement::execute(int array[], int & index)
{
	array[index]++;
}
