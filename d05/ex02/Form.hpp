/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:27:37 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:27:37 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

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
	Form(std::string name, int gradeToSign, int gradeToExecute);

	Form	&operator=(Form const & src);

	~Form(void);

	void	beSigned(Bureaucrat & src);

	int 	getSignGrade(void) const;
	int 	getExecuteGrade(void) const;
	bool	getStatus(void) const;
	std::string	getName(void) const;
	void	execute(Bureaucrat const & executor) const;
	virtual void	beExecuted(void) const;


	/* ****************   Exception classes   ***************** */

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

	class FormAlreadySigned : public virtual std::exception
	{
	public:
		FormAlreadySigned(void);
		FormAlreadySigned(FormAlreadySigned const & src);

		FormAlreadySigned	&operator=(FormAlreadySigned const & src);

		~FormAlreadySigned(void) throw();

		virtual const char* what() const throw();
	};
};


#endif
