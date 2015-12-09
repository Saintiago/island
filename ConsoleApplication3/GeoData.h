#pragma once
#include <vector>
#include <cstdlib>
#include <memory>
#include "islandMap.h"
#include "islandBlock.h"
#include "dataTypes.h"
#include "Grass.h"
#include "Rabbit.h"
#include "Hunter.h"
#include "Wolf.h"
#include <map>
#include <algorithm>
#include "Critter.h"

typedef shared_ptr<Critter> CritterPtr;
typedef vector<CritterPtr> CritterList;

class GeoData
{
public:

	GeoData();
	~GeoData();

	static Areal acceptableTerrain;

	CritterList GetCrittersAtPos(Pos pos);
	CritterList GetCritters();
	CritterList GetCrittersOf(CritterTypeList typeList);
	void CreateCritterAtRandomPos(CritterType type);
	void CreateCritter(CritterType type, Pos pos);
	islandMap GetMap();
	void randomizeWeather();
	void reactToWeather();
	void MoveIt();
	void KillIt();
	void BreedIt();
	void Extinct();
	

private:
	CritterList critters;
	islandMap mapOfIsland;

	Pos getRandomPosOf(terrainList terrain);
	Pos getRandomPos();
		
	void RegrowGrassByWeather(Pos pos);
	bool Kill(Pos where, CritterType who, int qty);
	void Create(Pos where, CritterType who, int qty);
	CritterPtr GetCritter(CritterType type);
	int CountCritter(CritterType type, Pos pos);

	IslandBlock getBlockAt(Pos pos);
	WeatherType getWeatherOnBlock(Pos pos);
	TerrainType getTerrainOnBlock(Pos pos);

	Directions GetDirections(Pos pos);
	
	
};

