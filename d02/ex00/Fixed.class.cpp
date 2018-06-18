//
// Created by Roman KYSLYY on 6/18/18.
//

#include "Fixed.class.hpp"

Fixed::Fixed() : _rawValue(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed& Fixed::operator=(Fixed const & src)
{
	std::cout << "Assignation operator called\n";
	this->_rawValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return this->_rawValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_rawValue = raw;
}
