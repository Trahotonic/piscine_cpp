//
// Created by Roman KYSLYY on 6/27/18.
//

#ifndef GIT_CPP_BASE_HPP
#define GIT_CPP_BASE_HPP

# include <iostream>

class Base
{
public:
	Base(void);
	Base(Base const & src);

	Base	&operator=(Base const & src);

	virtual ~Base(void);

	Base * generate(void);
};

#endif //GIT_CPP_BASE_HPP
