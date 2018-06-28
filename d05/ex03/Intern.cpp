//
// Created by Roman KYSLYY on 6/26/18.
//

#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern& Intern::operator=(Intern const &src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{}

Intern::NonExistingFormType::NonExistingFormType()
{}

Intern::NonExistingFormType::NonExistingFormType(NonExistingFormType const &src)
{
	*this = src;
}

Intern::NonExistingFormType& Intern::NonExistingFormType::operator=(NonExistingFormType const &src)
{
	(void)src;
	return *this;
}

Intern::NonExistingFormType::~NonExistingFormType() throw()
{}

const char* Intern::NonExistingFormType::what() const throw()
{
	return "Desired form type does not exist";
}

Form* Intern::makeForm(std::string const &type, std::string const &target)
{
	if (type != "robotomy request" && type != "presidental pardon" &&
			type != "shrubbery creation")
		throw NonExistingFormType();
	Form *ret;

	if (type == "robotomy request")
		ret = new RobotomyRequest(target);
	else if (type == "presidential pardon")
		ret = new PresidentialPardonForm(target);
	else
		ret = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << type << std::endl;
	return ret;
}