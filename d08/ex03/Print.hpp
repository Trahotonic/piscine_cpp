//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef GIT_CPP_PRINT_HPP
#define GIT_CPP_PRINT_HPP

# include <iostream>
# include "AInstruction.hpp"

class Print : public AInstruction
{
public:
	Print(void);
	Print(Print const & src);

	Print	&operator=(Print const & src);

	~Print(void);

	void	execute(int [], int&);
};


#endif //GIT_CPP_PRINT_HPP
