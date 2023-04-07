#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"

class Pomieszczenie;
class Grzejnik;
class Regulator;
class RegulatorBB;
class RegualtorPID;

class Symulacja {
private:
	Pomieszczenie* pomieszczenie;
	Grzejnik* grzejnik;
	Regulator* regulator;
	std::vector<float> Tablica_temp;
	std::vector<float> Tablica_mocy_grzejnika;
	std::vector<float> Tablica_czas;
	float czas;
	float wartosc_zadana;
public:
	Symulacja();
	Symulacja(Symulacja* s);
	~Symulacja();
	void iteracja(float dt);
	void przebieg(float dt, int ilosc);
	void zapisz();
	void set_regulator(Regulator* _regulator);
	void operator=(Symulacja* s);
	void grzej();
	void set_wartosc(float f) { wartosc_zadana = f; }
};