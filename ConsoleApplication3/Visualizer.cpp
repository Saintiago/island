#include "stdafx.h"
#include "Visualizer.h"

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
	showMap(geodata.GetMap(), geodata.GetCritters());
	cout << endl;
}

void Visualizer::showMap(islandMap map, Critter::CritterList critters)
{
	for (int j = 0; j < islandMap::MAP_HEIGHT; j++)
	{
		for (int i = 0; i < islandMap::MAP_WIDTH; i++)
		{
			drawBlock(map.map[i][j], { i, j }, critters);
		}
	}
}

void Visualizer::drawBlock(IslandBlock block, Pos pos, Critter::CritterList critters)
{
	Pos blockPos = { pos.x * m_blockWidth, pos.y * m_blockHeight };
	DrawTerrain(block.terrain, blockPos);
	DrawWeather(block.weather, blockPos);
	DrawBlockCritters(blockPos, GetCrittersAtPos({ pos.x, pos.y }, critters));
}

void Visualizer::DrawTerrain(TerrainType terrain, Pos pos)
{
	SetColor(terrainPattern[terrain]);
	for (int j = pos.y; j < (pos.y + m_blockHeight); j++)
	{
		for (int i = pos.x; i < (pos.x + m_blockWidth); i++)
		{
			putCursorToPosition(i, j);
			cout << " ";
		}
	}
}

void Visualizer::DrawWeather(WeatherType weather, Pos pos)
{
	putCursorToPosition(pos.x + m_blockWidth - 2, pos.y + m_blockHeight - 1);
	cout << this->weatherPattern[weather];
}

void Visualizer::DrawBlockCritters(Pos pos, Critter::CritterList critters)
{
	this->putCursorToPosition(pos.x, pos.y);
	vector<Critter>::iterator it = critters.begin();
	for (int j = pos.y; j < (pos.y + m_blockHeight); j++)
	{
		for (int i = pos.x; i < (pos.x + m_blockWidth); i++)
		{
			if (it == critters.end())
			{
				return;
			}
			putCursorToPosition(i, j);
			cout << critterPattern[(*it).getType()];
			it++;
		}
	}
}

void Visualizer::putCursorToPosition(int x, int y)
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

void Visualizer::SetColor(int code)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), code);
}

Critter::CritterList Visualizer::GetCrittersAtPos(Pos pos, Critter::CritterList critters)
{
	Critter::CritterList crittersAtpos;
	for (auto & critter : critters)
	{
		Pos critterPos = critter.getPos();
		if (pos.x == critterPos.x && pos.y == critterPos.y)
		{
			crittersAtpos.push_back(critter);
		}
	}
	return crittersAtpos;
}
