#include "stdafx.h"
#include <iostream>
#include "Visualizer.h"
#include "IslandBlock.h"
#include "islandMap.h"
#include "Windows.h"
#include "GeoData.h"
#include "Grass.h"

using namespace std;

Visualizer::Visualizer()
{
}


Visualizer::~Visualizer()
{
}

void Visualizer::show(GeoData geodata)
{
	clrscr();
	showMap(geodata.getMap);
	showCritters(geodata.getCritters());
	cout << endl;
}

void Visualizer::showMap(islandMap map)
{
	for (int i = 0; i < islandMap::MAP_WIDTH; i++)
	{
		for (int j = 0; j < islandMap::MAP_HEIGHT; j++)
		{
			this->putCursorToPosition((i * blockWidth), j * blockHeight);
			this->drawBlock(map.map[i][j]);
		}
	}
}

void Visualizer::showCritters(critterList critters)
{
	this->putCursorToPosition(0, 0);
	for (auto const & critter : critters)
	{
		Pos pos = critter.getPos();

		this->putCursorToPosition((pos.x * blockWidth), (pos.y * blockHeight + 1));
		this->drawCritter(critter.getType());
	}
}

void Visualizer::drawBlock(IslandBlock block)
{
	this->drawTerrain(block.terrain);
	this->drawWeather(block.weather);
	
}

void Visualizer::drawTerrain(TerrainType terrain)
{
	cout << this->terrainPattern[terrain];
}

void Visualizer::drawWeather(WeatherType weather)
{
	cout << this->weatherPattern[weather];
}

void Visualizer::drawCritter(CritterType type)
{
	cout << critterPattern[type];
}

void Visualizer::putCursorToPosition(int x, int y)
{
	this->gotoxy(x, y);
}


void Visualizer::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Visualizer::clrscr()
{
	system("cls");
}
