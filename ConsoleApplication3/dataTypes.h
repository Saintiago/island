#pragma once
#include <vector>
#include <map>

using namespace std;

enum class TerrainType;
enum class CritterType;

struct Pos
{
	int x;
	int y;
};

typedef vector<TerrainType> terrainList;
typedef vector<Pos> Positions;
typedef pair<TerrainType, Pos> Direction;
typedef vector<Direction> Directions;
typedef map<CritterType, terrainList> Areal;
typedef vector<CritterType> CritterTypeList;
typedef map<CritterType, CritterTypeList> Prey;

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

