#pragma once
#include <map>
#include "islandMap.h"
#include "Visualizer.h"
#include "dataTypes.h"
#include "GeoData.h"

class Simulation
{
public:
	Simulation();
	~Simulation();
	void start();

private:

	int iteration = 0;
	int lastId = 0;
	Visualizer display;
	GeoData geodata;

	void stop();
	void nextIteration();
	void waitForCommand();
	void populate();
	void placeGrass(int quantity);
};

