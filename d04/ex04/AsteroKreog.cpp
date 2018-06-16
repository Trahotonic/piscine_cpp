//
// Created by Roman Kyslyy on 6/16/18.
//

#include "AsteroKreog.hpp"

AsteroBocal::AsteroBocal(void) : _name("Asterobocal")
{}

AsteroBocal::AsteroBocal(AsteroBocal const &src)
{
    *this = src;
}

AsteroBocal& AsteroBocal::operator=(AsteroBocal const &src)
{
    if (this != &src)
        this->_name = src.getName();
    return *this;
}

AsteroBocal::~AsteroBocal(void)
{}

std::string AsteroBocal::beMined(StripMiner *) const
{
    return ("Flavium");
}

std::string AsteroBocal::beMined(DeepCoreMiner *) const
{
    return ("Thorite");
}

std::string AsteroBocal::getName() const
{
    return this->_name;
}
