//
// Created by Roman KYSLYY on 6/28/18.
//

#include <iostream>

template <typename T>
void	iter(T const array[], size_t size, void(function)(T))
{
	for (size_t i = 0; i < size; ++i)
		(function)(array[i]);
	std::cout << std::endl;
}

template <typename T>
void	function(T  data)
{
	std::cout << data << std::endl;
}

int main(void)
{
	std::string array1[] = {
			"hello",
			"world",
			"test_1",
			"test_2"
	};

	int			array2[] = {
			6, 21, 42
	};

	float 		array3[] = {
			6.6, 21.21, 42.42
	};

	::iter(array1, 4, function);
	::iter(array2, 3, function);
	::iter(array3, 3, function);
}