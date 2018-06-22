#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		std::cout << "Invalid arguments\nExit now\n";
		return (1);
	}
	std::ifstream   ifs(argv[1]);
	std::string     line;
	std::string     total;
	std::string     search = argv[2];
	std::string     replace = argv[3];

	if (ifs == NULL)
	{
		std::cout << "Input file does not exist\nExit now\n";
		return (1);
	}
	while (std::getline(ifs, line))
	{
		total += line;
		total += "\n";
	}
	if (!search.length() || !replace.length())
	{
		std::cout << total;
		return (0);
	}
	size_t index = 0;
	while (true)
	{
		index = total.find(search, index);
		if (index == std::string::npos)
			break ;
		total.replace(index, search.length(), replace);
		index += replace.length();
	}
	std::cout << total;
	return (0);
}