#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include "Simulation.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	Simulation matrix;
	matrix.start();

    return 0;
}

