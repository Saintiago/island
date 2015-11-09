#pragma once
#include "islandMap.h"
#include "IslandBlock.h"
#include "Grass.h"
#include "map"
#include "GeoData.h"
#include <string>
#include <iostream>
#include "Windows.h"

class Visualizer
{
public:
	Visualizer();
	~Visualizer();
	void show(GeoData);
	
private:

	int m_blockWidth = 16;
	int m_blockHeight = 8;

	map<TerrainType, int> terrainPattern = 
	{ 
		{ TerrainType::PLAIN, 47 },
		{ TerrainType::ROCK, 127 },
		{ TerrainType::WATER, 159 }
	};

	map<WeatherType, string> weatherPattern =
	{
		{ WeatherType::RAIN, " :" },
		{ WeatherType::SNOW, " *" },
		{ WeatherType::SUN, " o" },
		{ WeatherType::SUN_SUN, "oo" },
		{ WeatherType::RAIN_RAIN, "::" },
		{ WeatherType::SNOW_SNOW, "**" },
		{ WeatherType::SUN_RAIN, "o:" },
		{ WeatherType::SUN_SNOW, "o*" },
		{ WeatherType::RAIN_SNOW, ":*" },
	};

	map<CritterType, char> critterPattern =
	{
		{ CritterType::GRASS, '1' }
	};

	void showMap(islandMap map, Critter::CritterList critters);
	Critter::CritterList GetCrittersAtPos(Pos pos, Critter::CritterList critters);

	void drawBlock(IslandBlock tile, Pos pos, Critter::CritterList critters);
	void DrawTerrain(TerrainType, Pos pos);
	void DrawWeather(WeatherType, Pos pos);
	void DrawBlockCritters(Pos pos, Critter::CritterList critters);
	void putCursorToPosition(int x, int y);
	void clrscr();
	void SetColor(int code);
};

