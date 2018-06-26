/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:28:18 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:28:19 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequest.hpp"
#include "PresidentalPardonForm.hpp"

int main(void)
{
	Bureaucrat b("Roman", 25);
	Form &s = *new ShrubberyCreationForm("file");
	Form &r = *new RobotomyRequest("Dude");
	Form &p = *new PresidentalPardonForm("COD");

	try
	{
		b.signForm(s);
		b.execute(s);
	}
	catch (Bureaucrat::FormNotSigned e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::FormAlreadySigned e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		b.signForm(r);
		b.execute(r);
		b.execute(r);
		/* next line will not be executed */
		b.execute(r);
		b.execute(r);
	}
	catch (Bureaucrat::FormNotSigned e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << "Failed executing robotomy request\n" << std::endl;
	}
	catch (Form::FormAlreadySigned e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		b.execute(r);
	}
	catch (std::exception e)
	{
		std::cout << "Failed executing robotomy request\n" << std::endl;
	}


	try
	{
		b.execute(r);
	}
	catch (std::exception e)
	{
		std::cout << "Failed executing robotomy request\n" << std::endl;
	}

	try
	{
		b.execute(r);
	}
	catch (std::exception e)
	{
		std::cout << "Failed executing robotomy request\n" << std::endl;
	}

	try
	{
		b.execute(r);
	}
	catch (std::exception e)
	{
		std::cout << "Failed executing robotomy request\n" << std::endl;
	}

	try
	{
		b.signForm(p);
		b.execute(p);
	}
	catch (Bureaucrat::FormNotSigned e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::FormAlreadySigned e)
	{
		std::cout << e.what() << std::endl;
	}


	return 0;
}
