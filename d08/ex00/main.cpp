#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::list<int>  ints;

	ints.push_back(0);
	ints.push_back(2);
	ints.push_back(3);

	try
	{
		std::cout << easyfind(ints, 0) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << easyfind(ints, -1) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}