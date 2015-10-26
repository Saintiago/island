#pragma once
#include "islandMap.h"
#include "IslandBlock.h"
#include "Grass.h"
#include "map"
#include "GeoData.h"
#include <string>

class Visualizer
{
public:
	Visualizer();
	~Visualizer();
	void show(GeoData);
	
private:

	int blockWidth = 7;
	int blockHeight = 3;

	map<TerrainType, char> terrainPattern = 
	{ 
		{ TerrainType::PLAIN, 'P' },
		{ TerrainType::ROCK, 'R' },
		{ TerrainType::WATER, 'W' }
	};

	map<WeatherType, string> weatherPattern =
	{
		{ WeatherType::RAIN, "ra" },
		{ WeatherType::SNOW, "sn" },
		{ WeatherType::SUN, "su" },
		{ WeatherType::SUN_SUN, "susu" },
		{ WeatherType::RAIN_RAIN, "rara" },
		{ WeatherType::SNOW_SNOW, "snsn" },
		{ WeatherType::SUN_RAIN, "sura" },
		{ WeatherType::SUN_SNOW, "susn" },
		{ WeatherType::RAIN_SNOW, "rasn" },
	};

	map<CritterType, char> critterPattern =
	{
		{ CritterType::GRASS, '1' }
	};

	void showMap(islandMap);
	void showCritters(critterList);

	void drawBlock(IslandBlock);
	void drawTerrain(TerrainType);
	void drawWeather(WeatherType);
	void drawCritter(CritterType);
	void putCursorToPosition(int x, int y);
	void gotoxy(int x, int y);
	void clrscr();
};

