#pragma once
#include <vector>
#include "islandMap.h"
#include "islandBlock.h"
#include "dataTypes.h"
#include "Grass.h"
#include <map>
#include <algorithm>

class GeoData
{
public:
	GeoData();
	~GeoData();

	void placeCritter(Critter critter);
	Critter::CritterList GetCritters();
	islandMap GetMap();
	void randomizeWeather();
		
private:

	islandMap mapOfIsland;
	Pos GeoData::getRandomPosOf(terrainList terrain);
	Pos GeoData::getRandomPos();
	IslandBlock GeoData::getBlockAt(Pos pos);
	
	Critter::CritterList critters;
	map<CritterType, terrainList> acceptableTerrain = 
	{
		{ CritterType::GRASS, vector<TerrainType> {TerrainType::PLAIN} }
	};
};

