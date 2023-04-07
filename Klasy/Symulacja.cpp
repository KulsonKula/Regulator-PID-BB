#include "Symulacja.h"

Symulacja::Symulacja() {
	czas = 0;
	float L1 = 3; //rand() %1 +2;
	float L2 = 4.5; //rand() %3 +2;
	float L3 = 5.6; //rand() % 3 + 2;
	pomieszczenie= new Pomieszczenie(L1,L2,L3);
	L1 = 10000.0; //rand() % 10 + 1;
	grzejnik = new Grzejnik(L1);
	wartosc_zadana = 27;
}
Symulacja::Symulacja(Symulacja* s) {
	pomieszczenie = s->pomieszczenie;
	grzejnik = s->grzejnik;
	regulator = s->regulator;
	Tablica_temp = s->Tablica_temp;
	Tablica_mocy_grzejnika = s->Tablica_mocy_grzejnika;
	Tablica_czas = s->Tablica_czas;
	czas = s->czas;
	wartosc_zadana = s->wartosc_zadana;
}
Symulacja::~Symulacja() {
	//czyszczenie - zachowana zasada enkapsulacji
	Tablica_temp.clear();
	Tablica_mocy_grzejnika.clear();
	Tablica_czas.clear();
	delete grzejnik;
	delete pomieszczenie;
	delete regulator;
}

void Symulacja::iteracja(float dt) {
	pomieszczenie->dodajCieplo(grzejnik->get_cieplo());
	pomieszczenie->aktualizuj(dt);
}
void Symulacja::przebieg(float dt, int ilosc) {
	if (regulator == nullptr)throw "Prosze zmienic reglator!!!\n\n";
	for (int i = 0; i < ilosc; i++) {
		grzejnik->set_moc(regulator->sprawdz(regulator->steruj(dt, wartosc_zadana)));
		iteracja(dt);

		czas += dt;
		Tablica_temp.push_back(pomieszczenie->getTemperatura());
		Tablica_mocy_grzejnika.push_back(grzejnik->get_cieplo());
		Tablica_czas.push_back(czas);
		std::cout << Tablica_temp.at(i) << std::endl;
	}
	zapisz();
}
void Symulacja::zapisz() {
	std::ofstream plik;
	plik.open("Temperatura.csv");
	std::locale pol("pl_PL");
	plik.imbue(pol);
	plik.width(20);
	int temp = Tablica_temp.size();
	std::cout << "temp: "<<temp;
	for (int i = 0; i < temp; i++) {
		plik << Tablica_temp.at(i)<<";";
		plik <<  Tablica_mocy_grzejnika.at(i) << ";";
		plik <<  Tablica_czas.at(i)<<"\n";
	}
	plik.close();
}
void Symulacja::set_regulator(Regulator* _regulator) {
	regulator = _regulator;
}

void Symulacja::operator=(Symulacja* s) {
	pomieszczenie = s->pomieszczenie;
	grzejnik = s->grzejnik;
	regulator = s->regulator;
	Tablica_temp = s->Tablica_temp;
	Tablica_mocy_grzejnika = s->Tablica_mocy_grzejnika;
	Tablica_czas = s->Tablica_czas;
	czas = s->czas;
	wartosc_zadana = s->wartosc_zadana;
}
void Symulacja::grzej() {
	int a;
	float g;
	float f;
	bool running = true;
	std::cout << "Witaj w ustawieniach Symulacji\n";
	while (running == true) {
		std::cout << "Co chcialbys zrobic?\n";
		std::cout << "1 - zmienic regulator\n";
		std::cout << "2 - rozpocznij symulacje\n";
		std::cout << "3 - zakonczyc program\n";
		while (true) {
			std::cin >> a;
			if (std::cin.fail() == true) {
				std::cout << "Wykryto blad" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else break;
		}
		switch (a) {
		case 1:
		{
			std::cout << "Jaki chcesz wybrac regulator\n";
			std::cout << "1 - BB\n";
			std::cout << "2 - PID\n";
			while (true) {
				std::cin >> f;
				if (std::cin.fail() == true) {
					std::cout << "Wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');

				}
				else break;
			}
			if (f == 1) {
				regulator = new RegulatorBB();
			}
			else {
				regulator = new RegulatorPID();
			}
			regulator->set_grzejnik(grzejnik);
			regulator->set_pomieszczenie(pomieszczenie);
			set_regulator(regulator);
			break;
		}
		case 2:
		{
			std::cout << "czas probkowania\n";
			while (true) {
				std::cin >> f;
				if (std::cin.fail() == true) {
					std::cout << "Wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
			std::cout << "podaj ilosc probek";
			while (true) {
				std::cin >> g;
				if (std::cin.fail() == true) {
					std::cout << "Wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
			try {
				przebieg(f, g);
			}
			catch (const char* opisBledu) {
				std::cout << opisBledu;
			}
			break;
		}
		case 3:
			running = false;
			break;
		}
	}
}