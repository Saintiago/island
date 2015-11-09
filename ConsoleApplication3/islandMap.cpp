#include "stdafx.h"
#include "islandMap.h"
#include "IslandBlock.h"


islandMap::islandMap()
{
	init();
}


islandMap::~islandMap()
{
}

void islandMap::init()
{
	for (int i = 0; i < islandMap::MAP_WIDTH; i++)
	{
		for (int j = 0; j < islandMap::MAP_HEIGHT; j++)
		{
			map[i][j] = IslandBlock::IslandBlock();
		}
	}
}

void islandMap::randomizeWeather()
{
	for (int i = 0; i < islandMap::MAP_WIDTH; i++)
	{
		for (int j = 0; j < islandMap::MAP_HEIGHT; j++)
		{
			map[i][j].randomizeWeather();
		}
	}
}
