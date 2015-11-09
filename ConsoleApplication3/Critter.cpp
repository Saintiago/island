#include "stdafx.h"
#include "Critter.h"

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

void Critter::setType(CritterType type)
{
	m_type = type;
}

CritterType Critter::getType()
{
	return m_type;
}

terrainList Critter::canBeOn()
{
	terrainList terrain;
	terrain.push_back(TerrainType::PLAIN);
	return terrain;
}
