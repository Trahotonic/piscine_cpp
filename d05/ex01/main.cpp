//
// Created by Roman KYSLYY on 6/25/18.
//

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat  b("Roman", 50);

	std::cout << b.getName() << " " << b.getGrade() << "\n";

	++b;

	std::cout << b.getName() << " " << b.getGrade() << "\n";

	try {
		Form		f("42c", 10, 20);
		b.signForm(f);
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}

//	try {
//		Form		f("42c", 0, 0);
//		std::cout << "here\n";
//		b.signForm(f);
//	}
//	catch (Form::GradeTooHighException e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//	catch (Form::GradeTooLowException e)
//	{
//		std::cout << e.what() << std::endl;
//	}

	return 0;
}