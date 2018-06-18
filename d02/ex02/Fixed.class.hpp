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

};

Fixed		&min(Fixed & one, Fixed & two);
Fixed		&max(Fixed & one, Fixed & two);
const Fixed	&min(Fixed const & one, Fixed const & two);
const Fixed	&max(Fixed const & one, Fixed const & two);

std::ostream	&operator<<(std::ostream & o, Fixed const & src);

#endif //GIT_CPP_FIXED_CLASS_HPP
