#pragma once
#include <vector>
#include "Critter.h"

enum class TerrainType
{
	ROCK, WATER, PLAIN
};

enum class WeatherType
{
	SUN_SUN, 
	RAIN_RAIN, 
	SNOW_SNOW,
	SUN_RAIN,
	SUN_SNOW,
	RAIN_SNOW,
	SUN,
	RAIN,
	SNOW
};

enum class CritterType
{
	GRASS, RABBIT, WOLF, HUNTER
};

struct Pos
{
	int x;
	int y;
};

typedef vector<Critter> critterList;
typedef vector<TerrainType> terrainList;