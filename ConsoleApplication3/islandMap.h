#pragma once
#include "IslandBlock.h"

class islandMap
{
	
public:

	static const int MAP_WIDTH = 8;
	static const int MAP_HEIGHT = 4;

	IslandBlock map [islandMap::MAP_WIDTH][islandMap::MAP_HEIGHT];

	void randomizeWeather();

	islandMap();
	~islandMap();

private:
	void init();
};

