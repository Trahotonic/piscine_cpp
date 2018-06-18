#include "Brain.class.hpp"

Brain::Brain(void)
{
    std::string         str;
    std::stringstream   ss;
    int n;

    ss << this;
    str = ss.str();
    n = 2;
    while (str[n] != '\0')
    {
        if (str[n] >= 'a' && str[n] <= 'z')
            str[n] -= 32;
        n += 1;
    }
    this->address = str;
}

std::string Brain::identify(void) const
{
    return (this->address);
}