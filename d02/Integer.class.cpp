#include "Integer.class.hpp"

Integer::Integer(int const n) : _n(n)
{
	std::cout << "Integer constructor called with value " << n << std::endl;
}

int Integer::getValue(void) const
{
	return (this->_n);
}

Integer::~Integer(void)
{
	std::cout << "Integer destructor called with value " << getValue() << std::endl;
}