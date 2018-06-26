/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:26:40 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:26:41 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n* Trying to create a valid bureaucrat and "
			"increment/decrement him *\n\n";
	try
	{
		Bureaucrat	roman("Roman", 50);
		std::cout << roman;
		roman++;
		std::cout << roman;
		--roman;
		std::cout << roman;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n* Trying to create a bureaucrat with grade too high *\n\n";

	try
	{
		Bureaucrat	roman("Roman", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n* Trying to create a bureaucrat with grade too low *\n\n";

	try
	{
		Bureaucrat	ivan("Roman", 151);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
