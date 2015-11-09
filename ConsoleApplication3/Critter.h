#pragma once
#include "dataTypes.h"

class Critter
{
public:

	typedef vector<Critter> CritterList;

	Critter();
	virtual ~Critter();
	virtual terrainList canBeOn();
	void die();
	void setPos(Pos pos);
	void setType(CritterType type);
	Pos getPos();
	CritterType getType();

private:
	bool m_isAlive;
	Pos m_pos;
	CritterType m_type;
};

