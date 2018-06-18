//
// Created by Roman KYSLYY on 6/18/18.
//

#include <iostream>

int 		invalidDeep(std::string str)
{
	size_t n = 0;
	int numCount = 0;
	int opCount = 0;

	while (n < str.length())
	{
		if (isdigit(str[n]))
		{
			while (isdigit(str[n]) || str[n] == '.')
			{
				if (n < str.length() + 1 && str[n + 1] == '.')
					return 1;
				n++;
				numCount++;
			}
		}
		else if ()
		n++;
	}
}

int 		operatorsExist(std::string str)
{
	size_t n = 0;

	while (n < str.length())
	{
		if (str[n] == '+' || str[n] == '-' ||
				str[n] == '*' || str[n] == '/' ||
				str[n] == '%')
			return 1;
		n++;
	}
	return 0;
}

int 		supExist(std::string str)
{
	size_t n = 0;
	while (n < str.length())
	{
		if (str)
		n++;
	}
}

std::string	evalDeepest(std::string deepest)
{
	size_t n = 0;
	while (operatorsExist(deepest))
	{

	}
}
