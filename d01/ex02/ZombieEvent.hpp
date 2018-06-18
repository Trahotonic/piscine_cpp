#ifndef PISCINE_CPP_ZOMBIEEVENT_HPP
#define PISCINE_CPP_ZOMBIEEVENT_HPP

class   ZombieEvent
{
private:
    std::string _type;

public:
    ZombieEvent(void);
    ~ZombieEvent(void);

    void    setZombieType(std::string type);
    Zombie  *newZombie(std::string name);
};

#endif //PISCINE_CPP_ZOMBIEEVENT_HPP
