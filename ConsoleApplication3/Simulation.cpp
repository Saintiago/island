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
	randomizeWeather();
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

void Simulation::randomizeWeather()
{
	geodata.randomizeWeather();
}

void Simulation::populate()
{
	placeGrass(200);
}

void Simulation::placeGrass(int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		Grass grass;
		geodata.placeCritter(grass);
	}
}