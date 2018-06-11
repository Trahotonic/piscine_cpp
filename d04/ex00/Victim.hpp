#ifndef PISCINE_CPP_VICTIM_HPP
#define PISCINE_CPP_VICTIM_HPP

# include <iostream>

class Victim
{
protected:
    std::string _name;
public:
    Victim(void);
    Victim(std::string name);
    Victim(Victim const & src);
    ~Victim(void);

    Victim  &operator=(Victim const & src);

    std::string getName(void) const;

    virtual void        getPolymorphed(void) const;
};

std::ostream    &operator<<(std::ostream & o, Victim & src);

#endif //PISCINE_CPP_VICTIM_HPP
