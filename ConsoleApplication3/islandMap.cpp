#include "stdafx.h"
#include "islandMap.h"
#include "IslandBlock.h"


islandMap::islandMap()
{
	this->init();
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
	std::cout << std::endl;
}
