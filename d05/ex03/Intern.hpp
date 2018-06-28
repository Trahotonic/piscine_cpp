//
// Created by Roman KYSLYY on 6/26/18.
//

#ifndef GIT_CPP_INTERN_HPP
#define GIT_CPP_INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequest.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(Intern const & src);

	Intern	&operator=(Intern const & src);

	~Intern(void);

	Form	*makeForm(std::string const & type, std::string const & target);

	class NonExistingFormType : public virtual std::exception
	{
	public:
		NonExistingFormType(void);
		NonExistingFormType(NonExistingFormType const & src);

		NonExistingFormType	&operator=(NonExistingFormType const & src);

		~NonExistingFormType(void) throw();

		virtual const char* what() const throw();
	};
};

#endif //GIT_CPP_INTERN_HPP
