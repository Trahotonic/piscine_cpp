//
// Created by Roman KYSLYY on 6/18/18.
//

#include "Fixed.class.hpp"

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

