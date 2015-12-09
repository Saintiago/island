#include "stdafx.h"
#include "Grass.h"

Grass::GrassWeather Grass::weatherReaction = {
	{ WeatherType::RAIN, 1 },
	{ WeatherType::SUN, 1 },
	{ WeatherType::SNOW, 0 },
	{ WeatherType::RAIN_RAIN, 0 },
	{ WeatherType::SUN_SUN, -1 },
	{ WeatherType::SNOW_SNOW, -1 },
	{ WeatherType::SUN_SNOW, 0 },
	{ WeatherType::RAIN_SNOW, 0 },
	{ WeatherType::SUN_RAIN, 2 },
};

int Grass::limitOnBlock = 10;

Grass::Grass()
{
	setType(CritterType::GRASS);
}

Grass::~Grass()
{
}
