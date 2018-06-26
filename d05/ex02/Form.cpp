/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:27:40 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:27:40 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("DefaultName"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false),
                                                                    _gradeToSign(gradeToSign),
                                                                    _gradeToExecute(gradeToExecute)
{
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &src) : _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    *this = src;
}

Form& Form::operator=(Form const &src)
{
    this->_signed = src._signed;
    return *this;
}

Form::~Form() {

}

int Form::getSignGrade() const {
    return _gradeToSign;
}

int Form::getExecuteGrade() const {
    return _gradeToExecute;
}

std::string Form::getName() const {
    return _name;
}

bool Form::getStatus() const {
    return _signed;
}

void Form::beSigned(Bureaucrat &src) {
    if (src.getGrade() > _gradeToSign)
        throw GradeTooLowException();
	if (_signed)
		throw FormAlreadySigned();
    _signed = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw (GradeTooLowException());
	this->beExecuted();
}

void Form::beExecuted() const
{
}

Form::GradeTooHighException::GradeTooHighException()
{}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
    *this = src;
}

Form::GradeTooHighException& Form::GradeTooHighException::operator=(GradeTooHighException const &src)
{
    (void)src;
    return *this;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

Form::GradeTooLowException::GradeTooLowException()
{}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
    *this = src;
}

Form::GradeTooLowException& Form::GradeTooLowException::operator=(GradeTooLowException const &src)
{
    (void)src;
    return *this;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

Form::FormAlreadySigned::FormAlreadySigned()
{}

Form::FormAlreadySigned::FormAlreadySigned(FormAlreadySigned const &src)
{
	*this = src;
}

Form::FormAlreadySigned& Form::FormAlreadySigned::operator=(FormAlreadySigned const &src)
{
	(void)src;
	return *this;
}

Form::FormAlreadySigned::~FormAlreadySigned() throw()
{}

const char* Form::FormAlreadySigned::what() const throw()
{
	return "Form is already signed";
}
