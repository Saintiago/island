#pragma once
#include "dataTypes.h"

class Critter
{
public:

	Critter();
	~Critter();
	void die();
	void setPos(Pos pos);
	void setType(CritterType type);
	Pos getPos();
	CritterType GetType();
	bool IsAlive();
	void Move(Directions dirs, terrainList terrains);
	void Eat(bool Murder);
	bool IsHungry();
	bool GetBreeded();
	void SetBreeded(bool breeded);

protected:
	Pos m_pos;
	bool m_immortal = false;

private:

	Positions GetAcceptableDirections(Directions dirs, terrainList terrains);
	Pos ChoseDirection(Positions dirs);
	void SetPosition(Pos newPos);

	bool m_isAlive;
	bool m_hungry = false;
	bool m_breeded = false;
	CritterType m_type;
};

