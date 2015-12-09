#include "stdafx.h"
#include "GeoData.h"

Areal GeoData::acceptableTerrain =
{
	{ CritterType::GRASS, vector<TerrainType> {TerrainType::PLAIN} },
	{ CritterType::RABBIT, vector<TerrainType> {TerrainType::PLAIN} },
	{ CritterType::WOLF, vector<TerrainType> {TerrainType::PLAIN} },
	{ CritterType::HUNTER, vector<TerrainType> {TerrainType::PLAIN, TerrainType::ROCK} },
};

CritterTypeList walkerType = 
{
	CritterType::RABBIT,
	CritterType::HUNTER,
	CritterType::WOLF
};

CritterTypeList killerType = 
{
	CritterType::RABBIT,
	CritterType::HUNTER,
	CritterType::WOLF
};

CritterTypeList breederType =
{
	CritterType::RABBIT
};

Prey victims = 
{
	{ CritterType::RABBIT, { CritterType::GRASS } },
	{ CritterType::WOLF, { CritterType::RABBIT } },
	{ CritterType::HUNTER, { CritterType::RABBIT, CritterType::WOLF } }
};

GeoData::GeoData()
{
}


GeoData::~GeoData()
{
}

void GeoData::CreateCritterAtRandomPos(CritterType type)
{
	Pos critterPos = getRandomPosOf(acceptableTerrain[type]);
	CreateCritter(type, critterPos);
}

void GeoData::CreateCritter(CritterType type, Pos pos)
{
	CritterPtr & critter = GetCritter(type);
	if (CountCritter(critter->GetType(), pos) < Grass::limitOnBlock)
	{
		critter->setPos(pos);
		critters.push_back(critter);
	}
	else
	{
		critter = nullptr;
	}
}

Pos GeoData::getRandomPosOf(terrainList terrain)
{
	for (int i = 0; i < 1000; i++)
	{
		Pos pos = getRandomPos();
		IslandBlock block = mapOfIsland.map[pos.x][pos.y];
		if (find(terrain.begin(), terrain.end(), block.terrain) != terrain.end())
		{
			return pos;
			break;
		}
	}
	// throw exeption: terrain not found;
}

Pos GeoData::getRandomPos()
{
	int x = rand() % islandMap::MAP_WIDTH;
	int y = rand() % islandMap::MAP_HEIGHT;
	return { x, y };
}

IslandBlock GeoData::getBlockAt(Pos pos)
{
	return mapOfIsland.map[pos.x][pos.y];
}

CritterList GeoData::GetCritters()
{
	CritterList aliveCritters;
	for (auto & critter : critters)
	{
		if (critter->IsAlive())
		{
			aliveCritters.push_back(critter);
		}
	}
	return aliveCritters;
}

CritterList GeoData::GetCrittersOf(CritterTypeList types)
{
	CritterList critters = GetCritters();
	CritterList typeCritters;
	for (auto & critter : critters)
	{
		if (find(types.begin(), types.end(), critter->GetType()) != types.end())
		{
			typeCritters.push_back(critter);
		}
	}
	return typeCritters;
}

islandMap GeoData::GetMap()
{
	return mapOfIsland;
}

void GeoData::randomizeWeather()
{
	mapOfIsland.randomizeWeather();
}

void GeoData::reactToWeather()
{
	for (int i = 0; i < islandMap::MAP_HEIGHT; i++)
	{
		for (int j = 0; j < islandMap::MAP_WIDTH; j++)
		{
			if (TerrainType::PLAIN == getTerrainOnBlock({ j, i }))
			{
				RegrowGrassByWeather({ j, i });
			}
		}
	}
}

void GeoData::RegrowGrassByWeather(Pos pos)
{
	WeatherType weather = getWeatherOnBlock(pos);
	int lifeFactor = Grass::weatherReaction[weather];
	if (lifeFactor < 0)
	{
		Kill(pos, CritterType::GRASS, abs(lifeFactor));
	}
	if (lifeFactor > 0)
	{
		Create(pos, CritterType::GRASS, lifeFactor);
	}
	
}

bool GeoData::Kill(Pos where, CritterType who, int qty)
{
	bool isSomeoneDied = false;
	CritterList blockCritters = GetCrittersAtPos(where);
	for (auto & critter : blockCritters)
	{
		if (qty == 0)
		{
			break;
		}

		if (critter->GetType() == who)
		{
			critter->die();
			qty--;
			isSomeoneDied = true;
		}
	}
	return isSomeoneDied;
}

void GeoData::Create(Pos where, CritterType who, int qty)
{
	for (int i = qty; i > 0; i--)
	{
		CreateCritter(who, where);
		qty--;
	}
}

CritterPtr GeoData::GetCritter(CritterType type)
{
	if (type == CritterType::GRASS)
	{
		return CritterPtr(new Grass());
	}
	else if (type == CritterType::HUNTER)
	{
		return CritterPtr(new Hunter());
	}
	else if (type == CritterType::RABBIT)
	{
		return CritterPtr(new Rabbit());
	}
	else if (type == CritterType::WOLF)
	{
		return CritterPtr(new Wolf());
	}
}

CritterList GeoData::GetCrittersAtPos(Pos pos)
{
	CritterList crittersAtpos;
	for (auto & critter : GetCritters())
	{
		Pos critterPos = critter->getPos();
		if (pos.x == critterPos.x && pos.y == critterPos.y)
		{
			crittersAtpos.push_back(critter);
		}
	}
	return crittersAtpos;
}

int GeoData::CountCritter(CritterType type, Pos pos)
{
	int counter = 0;
	for (auto & critter : GetCritters())
	{
		Pos critterPos = critter->getPos();
		if (pos.x == critterPos.x && pos.y == critterPos.y && critter->GetType() == type)
		{
			counter++;
		}
	}
	return counter;
}

WeatherType GeoData::getWeatherOnBlock(Pos pos)
{
	IslandBlock block = getBlockAt(pos);
	return block.weather;
}

TerrainType GeoData::getTerrainOnBlock(Pos pos)
{
	IslandBlock block = getBlockAt(pos);
	return block.terrain;
}

void GeoData::MoveIt()
{
	CritterList walkers = GetCrittersOf(walkerType);
	for (auto & walker : walkers)
	{
		if (walker->GetType() == CritterType::RABBIT
			&& CountCritter(CritterType::GRASS, walker->getPos()) > 0)
		{
			return;
		}
		Directions dirs = GetDirections(walker->getPos());
		terrainList terrains = acceptableTerrain[walker->GetType()];
		walker->Move(dirs, terrains);
	}
}

void GeoData::KillIt()
{
	CritterList killers = GetCrittersOf(killerType);
	for (auto & killer : killers)
	{
		Pos killBox = killer->getPos();
		CritterTypeList victimList = victims[killer->GetType()];
		int victimIndex = rand() % victimList.size();
		killer->Eat(Kill(killBox, victimList.at(victimIndex), 1));
	}
}

void GeoData::BreedIt()
{
	for (int i = 0; i < islandMap::MAP_HEIGHT; i++)
	{
		for (int j = 0; j < islandMap::MAP_WIDTH; j++)
		{
			for (auto & breeder : breederType)
			{
				Pos pos = { j, i };
				int speciesCount = floor(CountCritter(breeder, pos) / 2);
				Create(pos, breeder, speciesCount);
			}
		}
	}
}

Directions GeoData::GetDirections(Pos pos)
{
	Positions positions = {
		{ pos.x, pos.y - 1 },
		{ pos.x + 1, pos.y - 1 },
		{ pos.x + 1, pos.y },
		{ pos.x + 1, pos.y + 1 },
		{ pos.x, pos.y + 1 },
		{ pos.x - 1, pos.y + 1 },
		{ pos.x - 1, pos.y },
		{ pos.x - 1, pos.y - 1 },
	};

	Positions existingPositions;
	for (auto & position : positions)
	{
		if (position.x >= 0
			&& position.x < islandMap::MAP_WIDTH
			&& position.y >= 0
			&& position.y < islandMap::MAP_HEIGHT)
		{
			existingPositions.push_back(position);
		}
	}
	
	Directions dirs;
	for (auto & exPos : existingPositions)
	{
		dirs.push_back(make_pair(mapOfIsland.map[exPos.x][exPos.y].terrain, exPos));;
	}

	return dirs;
}

void GeoData::Extinct()
{
	for (auto & critter : GetCritters())
	{
		if (critter->IsHungry())
		{
			critter->die();
		}
	}
}