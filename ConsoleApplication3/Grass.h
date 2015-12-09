#pragma once
#include <iostream>
#include "dataTypes.h"
#include <array>
#include "Critter.h"


using namespace std;

class Grass : public Critter
{
public:

	Grass();
	~Grass();

	typedef map <WeatherType, int> GrassWeather;
	static GrassWeather weatherReaction;
	static int limitOnBlock;
};

