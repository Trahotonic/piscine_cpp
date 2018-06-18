//
// Created by Roman KYSLYY on 6/18/18.
//

#ifndef GIT_CPP_FIXED_CLASS_HPP
#define GIT_CPP_FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
private:
	int					_rawValue;
	static const int	_scale = 8;
public:
	Fixed(void);
	Fixed(Fixed const & src);

	Fixed	&operator=(Fixed const & src);

	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif //GIT_CPP_FIXED_CLASS_HPP
