//
// Created by Roman KYSLYY on 6/27/18.
//

# include <iostream>

struct Data
{
	std::string s1;
	int 		n;
	std::string s2;
};

void	*serialize(void)
{
	std::string array = "abcdefghijklmnopqrstuvwxyz0123456789";

	char *	s1 = new char[8];
	int 	n = rand() % 1000000000;
	char *	s2 = new char[8];
	void	*ptr = ::operator new(20);
	for (int i = 0; i < 8; i++)
		s1[i] = array[rand() % 36];
	for (int i = 0; i < 8; i++)
		s2[i] = array[rand() % 36];
	std::cout << s1;
	std::cout << n;
	std::cout << s2 << std::endl;
	void	*anchor = ptr;
	char	*work = static_cast<char*>(ptr);
	for (int j = 0; j < 8; j++, work++)
		*work = s1[j];
	ptr = work;
	int	*toInt = static_cast<int*>(ptr);
	*toInt = n;
	for (int l = 0; l < 4; l++)
		toInt++;
	ptr = toInt;
	work = static_cast<char*>(ptr);
	for (int j = 0; j < 8; j++)
		work[j] = s2[j];
	return anchor;
}

Data	*deserialize(void * raw)
{
	void	*ptr = raw;
	char 	*work;
	int 	*toInt;
	Data *ret = new Data;

	ret->s1 = "";
	ret->s2 = "";
	work = static_cast<char*>(ptr);
	for (int m = 0; m < 8; m++, work++)
		ret->s1 += *work;
	ptr = work;
	toInt = static_cast<int*>(ptr);
	ret->n = *toInt;
	for (int k = 0; k < 4; k++)
		toInt++;
	ptr = toInt;
	work = static_cast<char*>(ptr);

	for (int m = 0; m < 8; m++, work++)
		ret->s2 += *work;
	return ret;
}

int	main(void)
{
	void	*ptr = serialize();

	Data	*data = deserialize(ptr);

	std::cout << data->s1 << data->n << data->s2 << std::endl;

	return 0;
}

