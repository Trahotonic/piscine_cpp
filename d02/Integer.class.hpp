//
// Created by Roman KYSLYY on 6/1/18.
//

#ifndef CPP_INTEGER_CLASS_HPP
#define CPP_INTEGER_CLASS_HPP

class   Integer
{
public:
	Integer(int const n);
	~Integer(void);

	int     getValue(void) const;
	Integer &operator=(Integer const & rhs);
	Integer operator+(Integer const & rhs) const;

private:
	int _n;
};

#endif //CPP_INTEGER_CLASS_HPP
