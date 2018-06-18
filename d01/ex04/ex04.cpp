#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *ptr = &string;
    std::string &ref = string;

    std::cout << *ptr << std::endl;
    std::cout << ref << std::endl;
    return (0);
}
