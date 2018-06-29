//
// Created by Roman KYSLYY on 6/29/18.
//

#include "AInstruction.hpp"

AInstruction::AInstruction()
{}

AInstruction::AInstruction(AInstruction const &src)
{
	*this = src;
}

AInstruction& AInstruction::operator=(AInstruction const &src)
{
	(void)src;
	return *this;
}

AInstruction::~AInstruction()
{}

void AInstruction::execute(int [], int &)
{}