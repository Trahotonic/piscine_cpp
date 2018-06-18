//
// Created by Roman Kyslyy on 5/31/18.
//

#include <iostream>
#include "Pony.class.hpp"

Pony::Pony(std::string name, std::string color, std::string age, std::string trick)
{
    this->_name = name;
    this->_age = age;
    this->_color = color;
    this->_trick = trick;
    std::cout << "Pony " << name << " is born" << std::endl;
}

Pony::~Pony(void)
{
    std::cout << "Pony " << this->_name << " died" << std::endl;
}

void Pony::ft_show_off(void)
{
    std::cout << "Hello\nMy name is " << this->_name << std::endl
              << "I am " << this->_color << " and " << this->_age
              << " years old" << std:: endl
              << "I learned a cool trick: " << this->_trick << std::endl
              << std::endl;
}