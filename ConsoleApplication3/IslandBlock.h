#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include "dataTypes.h"

using namespace std;

class IslandBlock
{
public:
	TerrainType terrain;
	WeatherType weather;

	IslandBlock();
	~IslandBlock();

		void init();
		void randomizeWeather();

private:
	array<TerrainType, 3> possibleTerrain = { TerrainType::ROCK, TerrainType::WATER, TerrainType::PLAIN };
	array<WeatherType, 9> possibleWeather = 
	{ 
		WeatherType::SUN_SUN,
		WeatherType::RAIN_RAIN,
		WeatherType::SNOW_SNOW,
		WeatherType::SUN_RAIN,
		WeatherType::SUN_SNOW,
		WeatherType::RAIN_SNOW,
		WeatherType::SUN,
		WeatherType::RAIN,
		WeatherType::SNOW
	};
	TerrainType getRandomTerrain();
	WeatherType getRandomWeather();
};

