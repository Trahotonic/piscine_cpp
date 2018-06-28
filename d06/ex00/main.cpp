//
// Created by Roman KYSLYY on 6/27/18.
//

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	Convert values(argv[1]);
	values.printChar();
	values.printInt();
	values.printFloat();
	values.printDouble();


	return 0;
}

