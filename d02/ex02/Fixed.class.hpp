//
// Created by Roman KYSLYY on 6/18/18.
//

#ifndef GIT_CPP_FIXED_CLASS_HPP
#define GIT_CPP_FIXED_CLASS_HPP

#include <iostream>
#include <math.h>

class Fixed
{
private:
	int					_rawValue;
	static const int	_scale = 8;
public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(const int);
	Fixed(const float);

	Fixed	&operator=(Fixed const & src);

	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float 	toFloat(void) const;

	bool	operator>(Fixed const & src);
	bool    operator<(Fixed const & src);
	bool    operator>=(Fixed const & src);
	bool    operator<=(Fixed const & src);
	bool    operator==(Fixed const & src);
	bool    operator!=(Fixed const & src);
	Fixed   operator+(Fixed const & src);
	Fixed   operator-(Fixed const & src);
	Fixed   operator*(Fixed const & src);
	Fixed   operator/(Fixed const & src);
	Fixed   &operator++();
	Fixed   &operator++(int);
	Fixed   &operator--();
	Fixed   &operator--(int);
	static Fixed &min(Fixed & a, Fixed & b);
	static Fixed const 	& min(Fixed const & a, Fixed const & b);
	static Fixed &max(Fixed & a, Fixed & b);
	static Fixed const 	& max(Fixed const & a, Fixed const & b);

};

std::ostream	&operator<<(std::ostream & o, Fixed const & src);

#endif //GIT_CPP_FIXED_CLASS_HPP