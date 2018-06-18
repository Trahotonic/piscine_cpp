//
// Created by Roman Kyslyy on 5/31/18.
//

# include <iostream>
# include <sstream>
# include <string>

#ifndef PISCINE_CPP_TEST_CLASS_HPP
#define PISCINE_CPP_TEST_CLASS_HPP

class   Brain
{
public:
    Brain(void);
    std::string    identify(void) const ;

private:
    std::string address;
};

#endif //PISCINE_CPP_TEST_CLASS_HPP
