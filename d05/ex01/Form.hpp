//
// Created by Roman KYSLYY on 6/25/18.
//

#ifndef GIT_CPP_FORM_HPP
#define GIT_CPP_FORM_HPP

#include <iostream>

class Form
{
private:
	std::string const	_name;
	bool				_signed;
	int 		const	_gradeToSign;
	int 		const	_gradeToExecute;
public:
	Form(void);
	Form(Form const & src);

	Form	&operator=(Form const & src);

	~Form(void);

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


#endif //GIT_CPP_FORM_HPP
