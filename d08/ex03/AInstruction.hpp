//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef AINSTRUCTION_HPP
#define AINSTRUCTION_HPP

# include <list>

class AInstruction
{
public:
	AInstruction(void);
	AInstruction(AInstruction const & src);

	AInstruction	&operator=(AInstruction const & src);

	~AInstruction(void);

	virtual void	execute(int [], int&);
};

#endif //GIT_CPP_AINSTRUCTION_HPP
