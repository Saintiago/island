#pragma once
#include <vector>
#include "islandMap.h"
#include "islandBlock.h"
#include "dataTypes.h"
#include "Grass.h"
#include <map>

class GeoData
{
public:
	GeoData();
	~GeoData();

	void placeCritter(Critter critter);
	critterList getCritters();
	islandMap getMap();

		
private:

	islandMap mapOfIsland;
	Pos GeoData::getRandomPosOf(terrainList terrain);
	Pos GeoData::getRandomPos();
	IslandBlock GeoData::getBlockAt(Pos pos);
	
	critterList critters;
	map<CritterType, terrainList> acceptableTerrain = 
	{
		{ CritterType::GRASS, vector<TerrainType> {TerrainType::PLAIN} }
	};
};

