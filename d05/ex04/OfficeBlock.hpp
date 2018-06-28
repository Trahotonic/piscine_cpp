//
// Created by Roman KYSLYY on 6/26/18.
//

#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock
{
private:
	OfficeBlock(OfficeBlock const & src);
	OfficeBlock	&operator=(OfficeBlock const & src);
	Bureaucrat 		*_signBureaucrat;
	Bureaucrat 		*_execBureaucrat;
	Intern 			*_intern;
public:
	OfficeBlock(void);
	OfficeBlock(Bureaucrat & signBureaucrat, Bureaucrat & execBureaucrat, Intern & intern);
	~OfficeBlock(void);

	void	setSign(Bureaucrat & signBureaucrat);
	void	setExec(Bureaucrat & signBureaucrat);
	void	setIntern(Intern & intern);

	void	makeBurocracy(std::string type, std::string target);
};

#endif //GIT_CPP_OFFICEBLOCK_HPP
