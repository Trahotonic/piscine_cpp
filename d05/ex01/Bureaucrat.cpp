//
// Created by Roman KYSLYY on 6/25/18.
//

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
			throw Bureaucrat::GradeTooHighException();
		}
		else if (grade > 150)
		{
			_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
		_grade = grade;
	}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
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
	return "New grade is too high\nGrade set to 1";
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
	return "New grade is too low\nGrade set to 150";
}

void Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade <= 0)
		{
			_grade = getGrade();
			throw Bureaucrat::GradeTooHighException();
		}
		else if (grade > 150)
		{
			_grade = getGrade();
			throw Bureaucrat::GradeTooLowException();
		}
		_grade = grade;
	}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}
