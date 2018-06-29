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
	if (!i)
	{
		std::cout << "Input file does not exist\n";
		return 1;
	}
	std::vector	<AInstruction*>	queue;
	std::string	total = "";
	std::string tmp;
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
	}
	i.close();
	int n = 0;
	while (n < static_cast<int>(total.length()))
	{
		if (total[n] == '>')
			queue.push_back(new NextBox);
		else if (total[n] == '<')
			queue.push_back(new PrevBox);
		else if (total[n] == '+')
			queue.push_back(new Increment);
		else if (total[n] == '-')
			queue.push_back(new Decrement);
		else if (total[n] == '[')
			queue.push_back(new GoFront);
		else if (total[n] == ']')
			queue.push_back(new GoBack);
		else if (total[n] == '.')
			queue.push_back(new Print);
		else if (isblank(total[n]) || total[n] == '\n')
		{
			n++;
			continue ;
		}
		else
		{
			std::cout << "Error reading file\n";
			return 1;
		}
		n++;
	}
	Mashine	machine(queue);
	machine.run();
	return 0;
}

