#pragma once
#include <iostream>
#include <fstream>


class Grzejnik {
private:
	float Moc_MAX;
	float Moc_a; //<0,1>
public:
	Grzejnik(float MAX);
	Grzejnik(Grzejnik* g);
	~Grzejnik();
	//metody dostepowe
	float get_cieplo();
	float get_moc_a();
	void set_moc(float i);

	void operator=(Grzejnik* g);
};