//
// Created by Roman KYSLYY on 6/24/18.
//

#ifndef GIT_CPP_BASE_CLASS_HPP
#define GIT_CPP_BASE_CLASS_HPP

class Base
{
protected:
	int _x;
	int _y;
public:
	Base(void);
	Base(Base const & src);

	Base	&operator=(Base const & src);

	~Base(void);

	void	setX(int);
	void 	setY(int);
	int 	getX(void) const;
	int 	getY(void) const;
};

#endif //GIT_CPP_BASE_CLASS_HPP
