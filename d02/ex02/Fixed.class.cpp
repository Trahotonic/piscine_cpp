//
// Created by Roman KYSLYY on 6/18/18.
//

#include "Fixed.class.hpp"

Fixed::Fixed() : _rawValue(0)
{
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::Fixed(const int x)
{
	this->setRawBits(x << Fixed::_scale);
}

Fixed::Fixed(const float x)
{
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
	this->_rawValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
	return this->_rawValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawValue = raw;
}

bool Fixed::operator>(Fixed const &src) const
{
	return this->toFloat() > src.toFloat();
}

bool Fixed::operator<(Fixed const &src) const
{
	return this->toFloat() < src.toFloat();
}

bool Fixed::operator>=(Fixed const &src) const
{
	return this->toFloat() >= src.toFloat();
}

bool Fixed::operator<=(Fixed const &src) const
{
	return this->toFloat() <= src.toFloat();
}

bool Fixed::operator==(Fixed const &src) const
{
	return this->toFloat() == src.toFloat();
}

bool Fixed::operator!=(Fixed const &src) const
{
	return this->toFloat() != src.toFloat();
}

Fixed Fixed::operator+(Fixed const &src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(Fixed const &src) const
{
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(Fixed const &src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(Fixed const &src) const
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

Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed& Fixed::operator--(int)
{
	Fixed	&ret = *this;
	this->setRawBits(this->getRawBits() - 1);
	return ret;
}

Fixed &Fixed::min(Fixed & one, Fixed & two)
{
	if (one.toFloat() < two.toFloat())
		return one;
	return two;
}

Fixed &Fixed::max(Fixed & one, Fixed & two)
{
	if (one.toFloat() > two.toFloat())
		return one;
	return two;
}

Fixed const 	&Fixed::min(Fixed const & one, Fixed const & two)
{
	if (one.toFloat() < two.toFloat())
		return one;
	return two;
}

Fixed const 	&Fixed::max(Fixed const & one, Fixed const & two)
{
	if (one.toFloat() > two.toFloat())
		return one;
	return two;
}

std::ostream	&operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}