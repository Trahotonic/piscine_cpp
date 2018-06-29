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

void Print::execute(int array[], int & index, int & comIndex, std::vector<AInstruction*> vec)
{
	(void)vec;
	std::cout << static_cast<char>(array[index]);
	comIndex++;
}
