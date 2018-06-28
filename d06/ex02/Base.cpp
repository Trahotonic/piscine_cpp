//
// Created by Roman KYSLYY on 6/27/18.
//

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{}

Base::Base(Base const &src)
{
	*this = src;
}

Base& Base::operator=(Base const &src)
{
	(void)src;
	return *this;
}

Base::~Base()
{}

Base* Base::generate(void)
{
	char i = rand() % 3;
	if (i == 2)
	{
		std::cout << "A\n";
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "B\n";
		return new B;
	}
	else
	{
		std::cout << "C\n";
		return new C;
	}
}