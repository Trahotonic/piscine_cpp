/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:27:30 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:27:30 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("DefaultName")
{
	_grade = 150;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		if (grade <= 0)
		{
			_grade = 1;
			throw Form::GradeTooHighException();
		}
		else if (grade > 150)
		{
			_grade = 150;
			throw Form::GradeTooLowException();
		}
		_grade = grade;
	}
	catch(Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::execute(Form const &src)
{
	if ((int)_grade > src.getExecuteGrade())
		throw Form::GradeTooLowException();
	if (!src.getStatus())
		throw FormNotSigned();
	std::cout << _name << " successfully executed form " << src.getName() << std::endl;
	src.execute(*this);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &src)
{
	_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::signForm(Form &src) {
	if (src.getSignGrade() < (int)_grade)
		throw Form::GradeTooHighException();
	src.beSigned(*this);
	std::cout << "Form " << src.getName() << " is signed by bureaucrat " << _name
			  << std::endl;
}

Bureaucrat Bureaucrat::operator++(int)
{
	setGrade(getGrade() - 1);
	return *this;
}

Bureaucrat Bureaucrat::operator++(void)
{
	Bureaucrat ret = Bureaucrat(*this);
	setGrade(getGrade() - 1);
	return ret;
}

Bureaucrat Bureaucrat::operator--(int)
{
	setGrade(getGrade() + 1);
	return *this;
}

Bureaucrat Bureaucrat::operator--()
{
	Bureaucrat ret = Bureaucrat(*this);
	setGrade(getGrade() + 1);
	return ret;
}

Bureaucrat Bureaucrat::operator+=(int x)
{
	setGrade(getGrade() - x);
	return *this;
}

Bureaucrat Bureaucrat::operator-=(int x)
{
	setGrade(getGrade() + x);
	return *this;
}

Bureaucrat::FormNotSigned::FormNotSigned()
{}

Bureaucrat::FormNotSigned::FormNotSigned(FormNotSigned const &src)
{
	*this = src;
}

Bureaucrat::FormNotSigned& Bureaucrat::FormNotSigned::operator=(FormNotSigned const &src)
{
	(void)src;
	return *this;
}

Bureaucrat::FormNotSigned::~FormNotSigned() throw()
{}

const char* Bureaucrat::FormNotSigned::what() const throw()
{
	return "Form is not signed";
}


void Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade <= 0)
		{
			_grade = getGrade();
			throw Form::GradeTooHighException();
		}
		else if (grade > 150)
		{
			_grade = getGrade();
			throw Form::GradeTooLowException();
		}
		_grade = grade;
	}
	catch(Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}
