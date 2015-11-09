#include "stdafx.h"
#include "GeoData.h"

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
		if (find(terrain.begin(), terrain.end(), block.terrain) != terrain.end())
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
	int y = rand() % islandMap::MAP_HEIGHT;
	return { x, y };
}

IslandBlock GeoData::getBlockAt(Pos pos)
{
	return mapOfIsland.map[pos.x][pos.y];
}

Critter::CritterList GeoData::GetCritters()
{
	return critters;
}

islandMap GeoData::GetMap()
{
	return mapOfIsland;
}

void GeoData::randomizeWeather()
{
	mapOfIsland.randomizeWeather();
}