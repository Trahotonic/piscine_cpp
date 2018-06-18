#include "Human.class.hpp"

std::string Human::identify(void) const
{
    return (this->_brain.identify());
}

Brain       Human::getBrain(void) const
{
    return (this->_brain);
}