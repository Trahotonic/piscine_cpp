//
// Created by Roman KYSLYY on 6/27/18.
//

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

void identify_from_pointer( Base * p )
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "A\n";
	if (b)
		std::cout << "B\n";
	if (c)
		std::cout << "C\n";
}

int main(void)
{
	srand(time(0));

	Base base;

	Base *ptr = base.generate();

	identify_from_pointer(ptr);
}
