//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef GIT_CPP_GOFRONT_HPP
#define GIT_CPP_GOFRONT_HPP

# include "AInstruction.hpp"

class GoFront : public AInstruction
{
public:
	GoFront(void);
	GoFront(GoFront const & src);

	GoFront	&operator=(GoFront const & src);

	~GoFront(void);

	void	execute(int [], int&);
};

#endif //GIT_CPP_GOFRONT_HPP
