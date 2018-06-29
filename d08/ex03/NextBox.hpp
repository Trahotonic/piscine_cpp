//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef GIT_CPP_NEXTBOX_HPP
#define GIT_CPP_NEXTBOX_HPP

# include "AInstruction.hpp"

class NextBox : public AInstruction
{
public:
	NextBox(void);
	NextBox(NextBox const & src);

	NextBox	&operator=(NextBox const & src);

	~NextBox(void);

	void	execute(int [], int&);
};

#endif //GIT_CPP_NEXTBOX_HPP
