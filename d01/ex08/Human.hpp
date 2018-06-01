//
// Created by Roman KYSLYY on 6/1/18.
//

#ifndef CPP_HUMAN_HPP
#define CPP_HUMAN_HPP

# include <iostream>

class   Human
{
private:
	void    meleeAttack(std::string const & target);
	void    rangedAttack(std::string const & target);
	void    intimidatingShout(std::string const & target);

public:
	void    action(std::string const & action_name, std::string const & target);
};


#endif //CPP_HUMAN_HPP
