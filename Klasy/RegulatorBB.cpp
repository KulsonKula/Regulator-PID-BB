#include "RegulatorBB.h"

float RegulatorBB::steruj(float time, float wartosc_zadana) {
	if (pomieszczenie->getTemperatura() >= wartosc_zadana) {
		return 0;
	}
	else {
		return 1;
	}
}