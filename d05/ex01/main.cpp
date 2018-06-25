//
// Created by Roman KYSLYY on 6/25/18.
//

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("Roman", 160);

	std::cout << b.getName() << " " << b.getGrade() << "\n";

	--b;

	std::cout << b.getName() << " " << b.getGrade() << "\n";

	return 0;
}