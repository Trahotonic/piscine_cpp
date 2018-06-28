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

#include "OfficeBlock.hpp"

int main(void)
{
	Bureaucrat roman("Roman", 10);

	Bureaucrat ivan("Ivan", 20);

	Intern intern;

	OfficeBlock block(roman, ivan, intern);

	try
	{
		block.makeBurocracy("shrubbery creation", "home");
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
