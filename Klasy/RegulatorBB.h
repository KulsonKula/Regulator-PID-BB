#pragma once


#include "Regulator.h"

class RegulatorBB : public Regulator {
public:
	RegulatorBB()  {};
	float steruj(float time, float wartosc_zadana);
	
};