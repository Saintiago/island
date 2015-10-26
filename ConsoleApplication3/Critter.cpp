#include "stdafx.h"
#include "Critter.h"
#include "dataTypes.h"


Critter::Critter()
{
}


Critter::~Critter()
{
}


void Critter::die()
{
	m_isAlive = false;
}

Pos Critter::getPos()
{
	return m_pos;
}

void Critter::setPos(Pos pos)
{
	m_pos = pos;
}

CritterType Critter::getType()
{
	return type;
}
