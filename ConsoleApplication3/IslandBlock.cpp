#include "stdafx.h"
#include "IslandBlock.h"
#include "dataTypes.h"
#include <string>

IslandBlock::IslandBlock()
{
	this->init();
}


IslandBlock::~IslandBlock()
{
}

void IslandBlock::init()
{
	terrain = getRandomTerrain();
	randomizeWeather();
}

void IslandBlock::randomizeWeather()
{
	weather = getRandomWeather();
}

TerrainType IslandBlock::getRandomTerrain()
{
	return this->possibleTerrain[rand() % this->possibleTerrain.size()];
}

WeatherType IslandBlock::getRandomWeather()
{
	return this->possibleWeather[rand() % this->possibleWeather.size()];
}
