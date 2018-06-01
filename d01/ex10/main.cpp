#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int         n = 1;
	std::string line;
	std::string total;
	struct stat st;

	if (argc > 1)
	{
		while (n < argc)
		{
			if ( stat(argv[n], &st) == 0 )
			{
				if ( st.st_mode & S_IFDIR )
				{
					std::cout << "cato9tails: " << argv[n] << ": Is directory\n";
					n += 1;
					continue ;
				}
			}
			std::ifstream ifs(argv[n]);
			std::cout << ifs << std::endl;
			if (ifs == 0)
			{
				std::cout << "cato9tails: " << argv[n] << ": No such file or directory\n";
				n += 1;
				continue ;
			}
			while (std::getline(ifs, line))
			{
				total += line;
				total += "\n";
			}
			std::cout << total;
			n += 1;
		}
	}
	else
	{
		while (std::getline(std::cin, line))
			std::cout << line << std::endl;
	}
	return (0);
}