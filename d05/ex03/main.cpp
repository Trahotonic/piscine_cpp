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
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat roman("Roman", 50);

	Intern intern;

	std::cout << "\n\n* Trying to create valid form and sign it *\n\n";

	try
	{
		Form *shrubberyForm = intern.makeForm("shrubbery creation", "home");
		roman.signForm(*shrubberyForm);
		roman.execute(*shrubberyForm);
	}
	catch (Intern::NonExistingFormType &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::FormAlreadySigned &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::FormNotSigned &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n* Trying to create an invalid form and sign it *\n\n";

	try
	{
		Form *invalidForm = intern.makeForm("something invalid", "invalid");
		roman.signForm(*invalidForm);
		roman.execute(*invalidForm);
	}
	catch (Intern::NonExistingFormType &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::FormAlreadySigned &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::FormNotSigned &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
