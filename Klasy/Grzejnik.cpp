#include "Grzejnik.h"

Grzejnik::Grzejnik(float MAX) {
	Moc_MAX = MAX;
	Moc_a = 1;
}
Grzejnik::Grzejnik(Grzejnik* g) {
	Moc_MAX = g->Moc_MAX;
	Moc_a = g->Moc_a;
}


float Grzejnik::get_cieplo() {
	return Moc_a * Moc_MAX;
}
void Grzejnik::set_moc(float i) {
	Moc_a = i;
}
float Grzejnik::get_moc_a() {
	return Moc_a;
}

Grzejnik::~Grzejnik() {

}
void Grzejnik::operator=(Grzejnik* g) {
	Moc_MAX = g->Moc_MAX;
	Moc_a = g->Moc_a;
}
