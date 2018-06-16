//
// Created by Roman Kyslyy on 6/16/18.
//

#include "KoalaSteroid.hpp"

BocalSteroid::BocalSteroid(void) : _name("Bocalsteroid")
{}

BocalSteroid::BocalSteroid(BocalSteroid const &src)
{
    *this = src;
}

BocalSteroid& BocalSteroid::operator=(BocalSteroid const &src)
{
    if (this != &src)
        this->_name = src.getName();
    return *this;
}

BocalSteroid::~BocalSteroid(void)
{}

std::string BocalSteroid::beMined(StripMiner *) const
{
    return ("Krpite");
}

std::string BocalSteroid::beMined(DeepCoreMiner *) const
{
    return ("Zazium");
}

std::string BocalSteroid::getName() const
{
    return this->_name;
}