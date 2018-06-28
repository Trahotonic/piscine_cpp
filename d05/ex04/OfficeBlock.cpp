//
// Created by Roman KYSLYY on 6/26/18.
//

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _signBureaucrat(NULL), _execBureaucrat(NULL), _intern(NULL)
{}

OfficeBlock::OfficeBlock(OfficeBlock const &src) : _signBureaucrat(src._signBureaucrat),
												   _execBureaucrat(src._execBureaucrat),
												   _intern(src._intern)
{}

OfficeBlock::OfficeBlock(Bureaucrat &signBureaucrat, Bureaucrat &execBureaucrat, Intern &intern) : _signBureaucrat(&signBureaucrat),
																								   _execBureaucrat(&execBureaucrat),
																								   _intern(&intern)
{}

OfficeBlock::~OfficeBlock()
{}

OfficeBlock& OfficeBlock::operator=(OfficeBlock const &src)
{
	_signBureaucrat = src._signBureaucrat;
	_execBureaucrat = src._execBureaucrat;
	_intern = src._intern;
	return *this;
}

void OfficeBlock::makeBurocracy(std::string type, std::string target)
{

}