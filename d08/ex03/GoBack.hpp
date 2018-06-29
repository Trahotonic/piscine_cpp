//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef GIT_CPP_GOBACK_HPP
#define GIT_CPP_GOBACK_HPP

# include "AInstruction.hpp"

class GoBack : public AInstruction
{
public:
	GoBack(void);
	GoBack(GoBack const & src);

	GoBack	&operator=(GoBack const & src);

	~GoBack(void);

	void	execute(int [], int&);
};

#endif //GIT_CPP_GOBACK_HPP
