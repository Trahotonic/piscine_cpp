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

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called\n";
	this->setRawBits(x << Fixed::_scale);
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called\n";
	this->setRawBits(roundf(x * (float)(1 << Fixed::_scale)));
}

int Fixed::toInt(void) const
{
	return this->_rawValue >> Fixed::_scale;
}

float Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / (float)(1 << Fixed::_scale);
}

Fixed& Fixed::operator=(Fixed const & src)
{
	std::cout << "Assignation operator called\n";
	this->_rawValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	return this->_rawValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawValue = raw;
}

std::ostream	&operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}