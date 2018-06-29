//
// Created by Roman KYSLYY on 6/29/18.
//

# include <iostream>
# include <fstream>
# include "Machine.hpp"
# include "GoFront.hpp"
# include "GoBack.hpp"
# include "Increment.hpp"
# include "Decrement.hpp"
# include "NextBox.hpp"
# include "PrevBox.hpp"
# include "Print.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments\n";
		return 1;
	}
	std::ifstream   i(argv[1]);
	std::list<AInstruction*>	queue;
	char 			tmp;
	while (!i.eof())
	{
		i >> tmp;
		std::cout << tmp;
		if (tmp == '>')
			queue.push_back(new NextBox);
		else if (tmp == '<')
			queue.push_back(new PrevBox);
		else if (tmp == '+')
			queue.push_back(new Increment);
		else if (tmp == '-')
			queue.push_back(new Decrement);
		else if (tmp == '[')
			queue.push_back(new GoFront);
		else if (tmp == ']')
			queue.push_back(new GoBack);
		else if (tmp == '.')
			queue.push_back(new Print);
		else
		{
			std::cout << "Error reading file\n";
			return 1;
		}
	}
	Mashine	machine(queue);
	machine.run();
	return 0;
}

