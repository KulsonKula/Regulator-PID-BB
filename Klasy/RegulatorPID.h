#pragma once
#include "Regulator.h"

class RegulatorPID : public Regulator {
	const float Kp = 4.0;
	const float Ki = 0.02;
	const float Kd = 0.1;

	float E;
	float EC;
	float dE;
	float Ep;
	float Up;
	float Ui;
	float Ud;
public:
	RegulatorPID() {
		E = 0;
		EC = 0;
		dE = 0;
		Ep = 0;
		Up = 0;
		Ui = 0;
		Ud = 0;
	};

	float steruj(float time, float wartosc_zadana);
};