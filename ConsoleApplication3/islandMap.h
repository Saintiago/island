#pragma once
#include "IslandBlock.h"

class islandMap
{
	
public:

	static const int MAP_WIDTH = 10;
	static const int MAP_HEIGHT = 10;

	IslandBlock map [islandMap::MAP_WIDTH][islandMap::MAP_HEIGHT];

	islandMap();
	~islandMap();

private:
	void init();
};

