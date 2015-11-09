#include "stdafx.h"
#include "Grass.h"

Grass::Grass()
{
	setType(CritterType::GRASS);
}

Grass::~Grass()
{
}

terrainList Grass::canBeOn()
{
	terrainList terrain;
	terrain.push_back(TerrainType::PLAIN);
	return terrain;
}


