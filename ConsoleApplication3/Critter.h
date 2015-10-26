#pragma once
#include "dataTypes.h"

class Critter
{
public:
	Critter();
	virtual ~Critter();
	void die();
	void setPos(Pos pos);
	Pos getPos();
	CritterType getType();
private:
	bool m_isAlive;
	Pos m_pos;
	CritterType type;
};

