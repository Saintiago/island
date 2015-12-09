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
	m_geo = geodata;
	clrscr();
	showMap(m_geo.GetMap(), m_geo.GetCritters());
	cout << endl;
}

void Visualizer::showMap(islandMap map, CritterList critters)
{
	for (int j = 0; j < islandMap::MAP_HEIGHT; j++)
	{
		for (int i = 0; i < islandMap::MAP_WIDTH; i++)
		{
			drawBlock(map.map[i][j], { i, j }, critters);
		}
	}
}

void Visualizer::drawBlock(IslandBlock block, Pos pos, CritterList critters)
{
	Pos blockPos = { pos.x * m_blockWidth, pos.y * m_blockHeight };
	DrawTerrain(block.terrain, blockPos);
	DrawWeather(block.weather, blockPos);
	DrawBlockCritters(blockPos, m_geo.GetCrittersAtPos({ pos.x, pos.y }));
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

void Visualizer::DrawBlockCritters(Pos pos, CritterList critters)
{
	this->putCursorToPosition(pos.x, pos.y);
	vector<CritterPtr>::iterator it = critters.begin();
	for (int j = pos.y; j < (pos.y + m_blockHeight); j++)
	{
		for (int i = pos.x; i < (pos.x + m_blockWidth); i++)
		{
			if (it == critters.end())
			{
				return;
			}
			putCursorToPosition(i, j);
			cout << critterPattern[(*it)->GetType()];
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
