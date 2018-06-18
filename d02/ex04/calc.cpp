//
// Created by Roman KYSLYY on 6/18/18.
//

#include <iostream>
#include "Fixed.class.hpp"

int 	returnError(void)
{
	std::cout << "Invalid argument\n";
	return (1);
}

int 	invalidExpression(std::string init)
{
	size_t	n = 0;
	int imbalance = 0;

	while (n < init.length())
	{
		if (std::isalpha(init[n]))
			return 1;
		if (init[n] == '(')
			imbalance++;
		if (init[n] == ')')
			imbalance--;
		n++;
	}
	if (imbalance)
		return 1;
	return 0;
}

int 	parExist(std::string work)
{
	size_t	n = 0;

	while (n < work.length())
	{
		if (work[n] == '(' || work[n] == ')')
			return 1;
		n++;
	}
	return (0);
}

int isDeepest(std::string work, int index)
{
	size_t	n = index + 1;

	while (n < work.length())
	{
		if (work[n] == ')')
			return (1);
		if (work[n] == '(')
			return (0);
		n++;
	}
	return 0;
}

std::string		findFirstDeep(std::string work)
{
	size_t n = 0;
	int m = 0;

	while (n < work.length())
	{
		if (work[n] == '(' && isDeepest(work, n))
		{
			m = n;
			while (work[m] != ')')
				m++;
			break ;
		}
		n++;
	}
	return work.substr(n, m + 1 - n);
}

std::string		evalDeepest(std::string	deepest)
{

}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid argument\n";
		return (1);
	}
	std::string work = argv[1];
	if (invalidExpression(work))
		return returnError();
	std::cout << findFirstDeep(work) << std::endl;
	return (0);
}
