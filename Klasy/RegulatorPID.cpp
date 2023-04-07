#include "RegulatorPID.h"

float RegulatorPID::steruj(float time, float wartosc_zadana) {
	//Up
	Ep = wartosc_zadana - pomieszczenie->getTemperatura()- E;
	E = wartosc_zadana - pomieszczenie->getTemperatura();
	Up = Kp * E;
	//Ui
	EC = EC + E * time;
	Ui = Ki * EC;
	//Ud
	dE = (E - Ep) / time;
	Ud = Kd * dE; 

	return(Ud + Ui + Up);

}