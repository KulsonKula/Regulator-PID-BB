#include <time.h>
#include "Klasy/Pomieszczenie.h"
#include "Klasy/Symulacja.h"
#include "Klasy/Grzejnik.h"
#include "Klasy/Regulator.h"
#include "Klasy/RegulatorBB.h"
#include "Klasy/RegulatorPID.h"

int main()
{ // polecany czas probkowania 10: ilosc probek dowolna >35
	Symulacja symulacja;
	symulacja.grzej();
	return 0;
};