#include "Pony.class.hpp"

void    ponyOnTheHeap(std::string name, std::string color,
					  std::string age, std::string trick)
{
    Pony    *pony = new Pony(name, color, age, trick);

    pony->ft_show_off();
    delete pony;
}

void    ponyOnTheStack(std::string name, std::string color,
					   std::string age, std::string trick)
{
    Pony    pony(name, color, age, trick);

    pony.ft_show_off();
}

int main(void)
{
    std::string heapAttributes[] = {
			"John",
			"Brown",
			"32",
			"gambling"
	};

	std::string	stackAttributes[] = {
			"James",
			"white",
			"50",
			"alcoholism"
	};

    ponyOnTheHeap(heapAttributes[0], heapAttributes[1],
				   heapAttributes[2], heapAttributes[3]);
    ponyOnTheStack(stackAttributes[0], stackAttributes[1],
				   stackAttributes[2], stackAttributes[3]);
    return (0);
}
