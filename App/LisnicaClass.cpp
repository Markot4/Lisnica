#include <iostream>
#include "LisnicaClass.h"
#include "Dionica.h"
#include "Obveznica.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
//ovo je samo test za pull request. sve ovdje za sad radi
namespace markot4 {
	void LisnicaClass::dodajVrijednosniPapir(VrijednosniPapir vp){
		papiri.push_back(vp);
		return;
	}

	void LisnicaClass::izbaciVrijednosniPapir(string oznaka) {
		int ix = -1;
		for (int i = 0; i < papiri.size();i++) {
			VrijednosniPapir &vp = papiri[i];
			if (vp.oznaka == oznaka) {
				ix = i;
			}
		}
		if (ix >= 0) {
			papiri.erase(papiri.begin() + ix);
		}
		return;
	}

	int LisnicaClass::promjenaKolicine(int promjena, string oznaka) {
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir& vp = papiri[i];
			if (vp.oznaka == oznaka) {
				vp.kolicina += promjena;
			}
		}
		return 0;
	}

	// promijena cijene vrijednosnim papirima sa oznakom u varijabli "oznaka"
	void LisnicaClass::promjenaCijene(double cijena, string oznaka) {
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir& vp = papiri[i];
			if (vp.oznaka == oznaka) {
				vp.cijena = cijena;
			}
		}
	}

	// promijena cijena svih vrijednosnih papira
	int LisnicaClass::promjenaCijene(string paragraf) {
		// pokusaj otvaranja datoteke zadane argumentom
		std::ifstream file(paragraf);
		if (!file.is_open()) {
			std::cerr << "Ne mogu otvoriti datoteku: " << paragraf << std::endl;
			return -1;
		}

		std::string line;
		std::unordered_map<std::string, double> noveCijene;

		// ucitavamo nove cijene iz datoteke
		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string oznaka;
			double cijena;

			// cita prvi dio linije do zareza i sprema ga u "oznaka"
			// pokusava ucitati cijenu iz preostalog dijela linije
			if (std::getline(ss, oznaka, ',') && ss >> cijena) {
				noveCijene[oznaka] = cijena;
			}
		}
		file.close();

		// azuriranje cijena svih vrijednosnih papira
		for (int i = 0; i < papiri.size(); i++) {
			if (noveCijene.count(papiri[i].oznaka)) {
				papiri[i].cijena = noveCijene[papiri[i].oznaka];
			}
		}
		return 0;
	}

	double LisnicaClass::vrijPoVrijPapir(string oznaka) {
		// provjerimo na koji se papir odnosi oznaka te vratimo kolicinu pomnozenu sa cijenom
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir& vp = papiri[i];
			if (vp.oznaka == oznaka) {
				//todo razlicito za dionicu i za obveznicu
				return vp.kolicina * vp.cijena;
			}
		}
		return 0;
	}

	// izracun vrijednosti svih dionica u listi papira
	double LisnicaClass::sveDionice() {
		double ukupno = 0.0;
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir& vp = papiri[i];

			//Dionica* dionica = dynamic_cast<Dionica*>(&vp);
			Dionica* dionica = static_cast<Dionica*>(&vp);
			if (dionica != nullptr) {
				ukupno += dionica->izracunajVrijednost();
			}
		}
		return ukupno;
	}

	double LisnicaClass::sveObveznice() {
		double ukupno = 0.0;
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir& vp = papiri[i];

			//Obveznica* obveznica = dynamic_cast<Obveznica*>(&vp);
			Obveznica* obveznica = static_cast<Obveznica*>(&vp);
			if (obveznica != nullptr) {
				ukupno += obveznica->izracunajVrijednost();
			}
		}
		return ukupno;
	}

	double LisnicaClass::vrijednostCijeleLisnice() {
		double ukupno = sveDionice() + sveObveznice();
		return ukupno;
	}

	void LisnicaClass::sadrzajCijeleLisnice() {
		cout << "Sadrzaj lisnice:" << endl;
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir& vp = papiri[i];
			cout << "Oznaka: " << vp.oznaka << ", Kolicina: " << vp.kolicina
				<< ", Cijena: " << vp.cijena << endl;
		}
	}
	LisnicaClass::LisnicaClass() {
		// NEDOVRSENO
	}
}