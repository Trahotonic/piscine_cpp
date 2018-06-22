#ifndef PISCINE_CPP_SORCERER_HPP
#define PISCINE_CPP_SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
private:
    std::string _name;
    std::string _title;

public:
    Sorcerer(void);
    Sorcerer(std::string name, std::string title);
    Sorcerer(Sorcerer const & src);
    ~Sorcerer(void);

    Sorcerer        &operator=(Sorcerer const & src);

    std::string     getName(void) const ;
    std::string     getTitle(void) const ;
    void            polymorph(Victim const & src);
};

std::ostream    &operator<<(std::ostream & o, Sorcerer & src);

#endif //PISCINE_CPP_SORCERER_HPP
