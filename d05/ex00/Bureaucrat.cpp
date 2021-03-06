/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:26:32 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:26:33 by rkyslyy          ###   ########.fr       */
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
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
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

Bureaucrat::GradeTooHighException::GradeTooHighException()
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &src)
{
	(void)src;
	return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &src)
{
	(void)src;
	return *this;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low\n";
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}
