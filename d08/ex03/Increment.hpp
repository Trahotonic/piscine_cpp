//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef GIT_CPP_INCREMENT_HPP
#define GIT_CPP_INCREMENT_HPP

# include "AInstruction.hpp"

class Increment : public AInstruction
{
public:
	Increment(void);
	Increment(Increment const & src);

	Increment	&operator=(Increment const & src);

	~Increment(void);

	void	execute(int [], int&);
};

#endif //GIT_CPP_INCREMENT_HPP
