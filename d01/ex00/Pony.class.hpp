#ifndef PONY_CLASS_HPP
#define PONY_CLASS_HPP

class   Pony
{
private:
    std::string _name;
    std::string _color;
    std::string _age;
    std::string _trick;
public:
    Pony(std::string name, std::string color, std::string age, std::string trick);
    ~Pony(void);

    void        ft_show_off(void);
};

#endif
