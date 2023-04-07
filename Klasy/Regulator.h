#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"

class Grzejnik;
class Pomieszczenie;

class Regulator {
protected:
	Pomieszczenie* pomieszczenie;
	Grzejnik* grzejnik;
public:
	Regulator() {
	};
	void set_pomieszczenie(Pomieszczenie* p) {
		pomieszczenie = p;
	}
	void set_grzejnik(Grzejnik* g) {
		grzejnik = g;
	}
	virtual float steruj(float time, float wartosc_zadana) { return 1; };
	float sprawdz(float a) {
		if (a <= 1 && a >= 0) {
			return a;
		}
		else if (a > 1) {
			return 1;
		}
		else {
			return 0;
		}
	};
};