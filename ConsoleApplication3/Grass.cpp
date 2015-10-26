#include "stdafx.h"
#include "Grass.h"

Grass::Grass()
{
	type = CritterType::GRASS;
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


