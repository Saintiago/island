#include "stdafx.h"
#include "Simulation.h"
#include "Visualizer.h"
#include "Grass.h"
#include "islandMap.h"
#include "GeoData.h"

Simulation::Simulation()
{
	display = Visualizer::Visualizer();
	geodata = GeoData::GeoData();
}


Simulation::~Simulation()
{
}


void Simulation::start()
{
	iteration++;
	populate();
	display.show(geodata);
	waitForCommand();
}


void Simulation::stop()
{
}


void Simulation::NextIteration()
{
	geodata.KillIt();
	geodata.Extinct();
	geodata.MoveIt();
	geodata.BreedIt();
	geodata.reactToWeather();
	geodata.randomizeWeather();
	display.show(geodata);
	iteration++;
}


void Simulation::waitForCommand()
{
 	while (_getch() != VK_ESCAPE)
	{
		NextIteration();
	}
}

void Simulation::populate()
{
	placeCritters(CritterType::GRASS, 100);
	placeCritters(CritterType::RABBIT, 10);
	placeCritters(CritterType::HUNTER, 1);
}

void Simulation::placeCritters(CritterType type, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		geodata.CreateCritterAtRandomPos(type);
	}
}`