//
// Created by Roman KYSLYY on 6/28/18.
//

# include "Array.hpp"

# define TYPE int

int main(void)
{
	Array<TYPE> array(10);

	array[0] = 'a';
	array[1] = 'b';
	array[3] = 'c';

	try
	{
		std::cout << std::setprecision(2) << std::fixed << array[0] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array[1] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array[2] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array[3] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array[11] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;


	Array<TYPE> array2 = array;

	try
	{
		std::cout << std::setprecision(2) << std::fixed << array2[0] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array2[1] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array2[2] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array2[3] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array2[11] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<TYPE> array3;

	try
	{
		std::cout << std::setprecision(2) << std::fixed << array3[0] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array3[1] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array3[2] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array3[3] << std::endl;
		std::cout << std::setprecision(2) << std::fixed << array3[11] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
