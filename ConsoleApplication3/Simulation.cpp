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


void Simulation::nextIteration()
{
}


void Simulation::waitForCommand()
{
}


void Simulation::populate()
{
	placeGrass(50);
}

void Simulation::placeGrass(int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		Grass grass;
		geodata.placeCritter(grass);
	}
}