//
// Created by Roman KYSLYY on 6/29/18.
//

#include "span.hpp"

int main(void)
{
	Span	span(10);

//	try
//	{
//		span.addNumber(1);
//		span.addNumber(2);
//		span.addNumber(7);
//	}
//	catch (std::exception &e)
//	{
//		std::cout << e.what() << std::endl;
//	}

	try
	{
		std::cout << span.longestSpan() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
