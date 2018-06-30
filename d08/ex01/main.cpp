//
// Created by Roman KYSLYY on 6/29/18.
//

#include "span.hpp"

int main(void)
{
	Span	span(5000);

	try
	{
		span.addNumber(1);
		span.addNumber(2);
		span.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> vector;

	for (int i = 5; i < 100; ++i)
		vector.push_back(i);

	try
	{
		span.addNumber(vector.begin(), vector.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Longest: " << span.longestSpan() << std::endl;
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
