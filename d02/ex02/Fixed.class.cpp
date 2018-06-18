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

bool Fixed::operator>(Fixed const &src)
{
	return this->toFloat() > src.toFloat();
}

bool Fixed::operator<(Fixed const &src)
{
	return this->toFloat() < src.toFloat();
}

bool Fixed::operator>=(Fixed const &src)
{
	return this->toFloat() >= src.toFloat();
}

bool Fixed::operator<=(Fixed const &src)
{
	return this->toFloat() <= src.toFloat();
}

bool Fixed::operator==(Fixed const &src)
{
	return this->toFloat() == src.toFloat();
}

bool Fixed::operator!=(Fixed const &src)
{
	return this->toFloat() != src.toFloat();
}

Fixed Fixed::operator+(Fixed const &src)
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(Fixed const &src)
{
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(Fixed const &src)
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(Fixed const &src)
{
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed& Fixed::operator++(int)
{
	Fixed	&ret = *this;
	this->setRawBits(this->getRawBits() + 1);
	return ret;
}

Fixed	&min(Fixed & one, Fixed & two)
{
	if (one.toFloat() <= two.toFloat())
		return one;
	return two;
}

Fixed	&max(Fixed & one, Fixed & two)
{
	if (one.toFloat() >= two.toFloat())
		return one;
	return two;
}

const Fixed	&min(Fixed const & one, Fixed const & two)
{
	if (one.toFloat() <= two.toFloat())
		return one;
	return two;
}

const Fixed	&max(Fixed const & one, Fixed const & two)
{
	if (one.toFloat() >= two.toFloat())
		return one;
	return two;
}

std::ostream	&operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}