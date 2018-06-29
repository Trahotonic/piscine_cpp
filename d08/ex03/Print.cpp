//
// Created by Roman KYSLYY on 6/29/18.
//

#include "Print.hpp"

Print::Print()
{}

Print::Print(Print const &src)
{
	*this = src;
}

Print& Print::operator=(Print const &src)
{
	(void)src;
	return *this;
}

Print::~Print()
{}

void Print::execute(int array[], int & index)
{
	std::cout << static_cast<char>(array[index]);
}
