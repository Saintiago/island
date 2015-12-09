#include "stdafx.h"
#include "Critter.h"

Critter::Critter()
{
}


Critter::~Critter()
{
}


void Critter::die()
{
	if (!m_immortal)
	{
		m_isAlive = false;
	}
}

Pos Critter::getPos()
{
	return m_pos;
}

void Critter::setPos(Pos pos)
{
	m_pos = pos;
}

void Critter::setType(CritterType type)
{
	m_type = type;
}

CritterType Critter::GetType()
{
	return m_type;
}

bool Critter::IsAlive()
{
	return m_isAlive;
}

void Critter::Move(Directions dirs, terrainList terrains)
{
	Positions positions = GetAcceptableDirections(dirs, terrains);
	if (positions.size() > 0)
	{
		Pos newPos = ChoseDirection(positions);
		SetPosition(newPos);
	}
}

Positions Critter::GetAcceptableDirections(Directions dirs, terrainList terrains)
{
	Positions canWalkTo;
	for (auto & dir : dirs)
	{
		if (find(terrains.begin(), terrains.end(), dir.first) != terrains.end())
		{
			canWalkTo.push_back(dir.second);
		}
	}
	return canWalkTo;
}

Pos Critter::ChoseDirection(Positions positions)
{
	int index = rand() % positions.size();
	int i = 0;
	for (auto & pos : positions)
	{
		if (i == index)
		{
			return pos;
		}
		i++;
	}
}

void Critter::SetPosition(Pos newPos)
{
	m_pos = newPos;
}

void Critter::Eat(bool Murder)
{
	m_hungry = !Murder;
}

bool Critter::IsHungry()
{
	return m_hungry;
}

void Critter::SetBreeded(bool breeded)
{
	m_breeded = breeded;
}

bool Critter::GetBreeded()
{
	return m_breeded;
}