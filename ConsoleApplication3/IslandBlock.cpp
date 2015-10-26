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
	this->terrain = this->getRandomTerrain();
	this->weather = this->getRandomWeather();
}


TerrainType IslandBlock::getRandomTerrain()
{
	return this->possibleTerrain[rand() % this->possibleTerrain.size()];
}


WeatherType IslandBlock::getRandomWeather()
{
	return this->possibleWeather[rand() % this->possibleWeather.size()];
}
