#include "stdafx.h"
#include "GeoData.h"
#include "islandMap.h"
#include <algorithm>


GeoData::GeoData()
{
}


GeoData::~GeoData()
{
}

void GeoData::placeCritter(Critter critter)
{
	Pos critterPos = getRandomPosOf(acceptableTerrain[critter.getType()]);
	critter.setPos(critterPos);
	critters.push_back(critter);
}

Pos GeoData::getRandomPosOf(terrainList terrain)
{
	for (int i = 0; i < 1000; i++)
	{
		Pos pos = getRandomPos();
		IslandBlock block = mapOfIsland.map[pos.x][pos.y];
		if (find(terrain.begin(), terrain.end(), block.terrain))
		{
			return pos;
			break;
		}
	}
	// throw exeption: terrain not found;
}

Pos GeoData::getRandomPos()
{
	int x = rand() % islandMap::MAP_WIDTH;
	int y = rand() % islandMap::MAP_WIDTH;
	return { x, y };
}

IslandBlock GeoData::getBlockAt(Pos pos)
{
	return mapOfIsland.map[pos.x][pos.y];
}

critterList GeoData::getCritters()
{
	return critters;
}

islandMap GeoData::getMap()
{
	return mapOfIsland;
}
