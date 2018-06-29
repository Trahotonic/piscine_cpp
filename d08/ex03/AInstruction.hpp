//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef AINSTRUCTION_HPP
#define AINSTRUCTION_HPP

# include <vector>

class AInstruction
{
protected:
	int _pair;
public:
	AInstruction(void);
	AInstruction(AInstruction const & src);

	AInstruction	&operator=(AInstruction const & src);

	~AInstruction(void);

	virtual void	execute(int [], int&, int&, std::vector<AInstruction*>);
	int 	getPair(void);
};

#endif //GIT_CPP_AINSTRUCTION_HPP
