//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef GIT_CPP_IMACHINE_HPP
#define GIT_CPP_IMACHINE_HPP

# include <list>
# include "AInstruction.hpp"

class Mashine
{
private:
	int 	_array[30000];
	int 	_index;
	std::list<AInstruction*>	_queue;
public:
	Mashine(void);
	Mashine(Mashine const & src);
	Mashine(std::list<AInstruction*>);

	Mashine	&operator=(Mashine const & src);

	~Mashine(void);

	void	run(void);
};

#endif //GIT_CPP_IMACHINE_HPP
