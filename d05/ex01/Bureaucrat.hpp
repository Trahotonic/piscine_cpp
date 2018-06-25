//
// Created by Roman KYSLYY on 6/25/18.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const	_name;
	unsigned int 		_grade;
public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat(std::string name, int grade);

	Bureaucrat	&operator=(Bureaucrat const & src);

	~Bureaucrat(void);

	void 		signForm(Form & src);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		setGrade(int);

	Bureaucrat	operator++(void);
	Bureaucrat  operator++(int);
	Bureaucrat	operator--(void);
	Bureaucrat  operator--(int);
	Bureaucrat	operator+=(int);
	Bureaucrat  operator-=(int);

	class GradeTooHighException : public virtual std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const & src);

		GradeTooHighException	&operator=(GradeTooHighException const & src);

		~GradeTooHighException(void) throw();

		virtual const char* what() const throw();
	};
	class GradeTooLowException : public virtual std::exception
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const & src);

		GradeTooLowException	&operator=(GradeTooLowException const & src);

		~GradeTooLowException(void) throw();

		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & src);

#endif //GIT_CPP_BUREAUCRAT_HPP
