//
// Created by Roman KYSLYY on 6/25/18.
//

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "* Creating and incrementing new Bureaucrat Roman *\n";
	std::cout << "______________________________________________________\n";
	Bureaucrat  roman("Roman", 51);

	std::cout << roman;

	++roman;

	std::cout << roman;
	std::cout << "______________________________________________________\n\n\n";



	std::cout << "* Creating a valid form and trying to sign it with grade too low *\n";
	std::cout << "______________________________________________________\n";
	try {
		Form		f("42c", 10, 20);
		roman.signForm(f);
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "______________________________________________________\n\n\n";



	std::cout << "*** Trying to create an invalid form ***\n";
	std::cout << "______________________________________________________\n";
	try {
		Form		f("42c", 0, 0);
		roman.signForm(f);
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "______________________________________________________\n\n\n";


	std::cout << "*** Incrementing Bureaucrat Roman to grade 5 ***\n";
	std::cout << "______________________________________________________\n";

	roman += 45;
	std::cout << roman;

	std::cout << "______________________________________________________\n\n\n";


	std::cout << "*** Trying to sign a valid form by bureaucrat with valid grade ***\n";
	std::cout << "______________________________________________________\n";

	try {
		Form		f("42c", 25, 26);
		roman.signForm(f);
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "______________________________________________________\n\n\n";

	std::cout << "*** Creating a valid form again and trying to sign it twice ***\n";
	std::cout << "______________________________________________________\n";

	Form		f("42c", 25, 26);
	roman.signForm(f);
	roman.signForm(f);
	std::cout << "______________________________________________________\n\n\n";

	return 0;
}