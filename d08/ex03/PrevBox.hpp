//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef GIT_CPP_PREVBOX_HPP
#define GIT_CPP_PREVBOX_HPP

# include "AInstruction.hpp"

class PrevBox : public AInstruction
{
public:
	PrevBox(void);
	PrevBox(PrevBox const & src);

	PrevBox	&operator=(PrevBox const & src);

	~PrevBox(void);

	void	execute(int [], int&);
};

#endif //GIT_CPP_PREVBOX_HPP
