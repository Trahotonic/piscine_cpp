//
// Created by Roman KYSLYY on 6/14/18.
//

#ifndef GIT_CPP_CURE_HPP
#define GIT_CPP_CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(std::string const & type);
    Cure(Cure const & src);

    Cure    &operator=(Cure const & src);

    ~Cure(void);

    AMateria     *clone(void) const;
    void    use(ICharacter & target);
};

#endif //GIT_CPP_CURE_HPP
