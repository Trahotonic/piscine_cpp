//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef GIT_CPP_DECREMENT_HPP
#define GIT_CPP_DECREMENT_HPP

# include "AInstruction.hpp"

class Decrement : public AInstruction
{
public:
	Decrement(void);
	Decrement(Decrement const & src);

	Decrement	&operator=(Decrement const & src);

	~Decrement(void);

	void	execute(int [], int&, int&, std::vector<AInstruction*>);
};

#endif //GIT_CPP_DECREMENT_HPP
