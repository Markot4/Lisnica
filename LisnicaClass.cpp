#include <iostream>
#include "LisnicaClass.h"
#include "Dionica.h"
#include "Obveznica.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
//ovo je samo test za pull request. sve ovdje za sad radi
namespace markot4 {
	void LisnicaClass::dodajVrijednosniPapir(VrijednosniPapir *vp){
		papiri.push_back(vp);
		return;
	}

	bool LisnicaClass::izbaciVrijednosniPapir(string oznaka) {
		int ix = -1;
		for (int i = 0; i < papiri.size();i++) {
			VrijednosniPapir *vp = papiri[i];
			if (vp->oznaka == oznaka) {
				ix = i;
			}
		}
		if (ix >= 0) {
			papiri.erase(papiri.begin() + ix);
			return true;
		}
		return false;
	}

	int LisnicaClass::promjenaKolicine(int promjena, string oznaka) {
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir *vp = papiri[i];
			if (vp->oznaka == oznaka) {
				vp->kolicina += promjena;
				if (vp->kolicina <= 0) {
					izbaciVrijednosniPapir(oznaka);
					return 0;
				}
				return vp->kolicina;
			}
		}
		throw invalid_argument("Ne postoji vrijednosni papir"); //relativno
	}

	// promijena cijene vrijednosnim papirima sa oznakom u varijabli "oznaka"
	void LisnicaClass::promjenaCijene(double cijena, string oznaka) {
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir *vp = papiri[i];
			if (vp->oznaka == oznaka) {
				vp->cijena = cijena;
				return;
			}
		}
		throw invalid_argument("Ne postoji vrijednosni papir");
	}

	double LisnicaClass::vrijPoVrijPapir(string oznaka) {
		// provjerimo na koji se papir odnosi oznaka te vratimo kolicinu pomnozenu sa cijenom
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir *vp = papiri[i];
			if (vp->oznaka == oznaka) {

				//todo razlicito za dionicu i za obveznicu
				return vp->izracunajVrijednost();
			}
		}
		return 0;
	}

	// izracun vrijednosti svih dionica u listi papira
	double LisnicaClass::sveDionice() {
		double ukupno = 0.0;

		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir *vp = papiri[i];
			if (vp->isDionica()) {
				ukupno += vp->izracunajVrijednost();
			}
		}
		return ukupno;
	}

	double LisnicaClass::sveObveznice() {
		double ukupno = 0.0;
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir *vp = papiri[i];
			if (vp->isObveznica()) {
				ukupno += vp->izracunajVrijednost();
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
			VrijednosniPapir *vp = papiri[i];
			cout << "Oznaka: " << vp->oznaka << ", Kolicina: " << vp->kolicina
				<< ", Cijena: " << vp->cijena << endl;
		}
	}
	LisnicaClass::LisnicaClass() {
		// NEDOVRSENO
	}

	bool LisnicaClass::dodajDionicu(double cijena, int kolicina, string oznaka) {
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir* vp = papiri[i];
			if (vp->oznaka == oznaka) {
				return false; //Dionica vec postoji. Vracamo false
			}
		}
		// vrijednosni papir s tom oznakom ne postoji
		Dionica *d = new Dionica(oznaka, kolicina, cijena);
		dodajVrijednosniPapir(d);
		return true;
	}

	bool LisnicaClass::dodajObveznicu(string oznaka, double cijena, int kolicina, double nominalnaCijena) {
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir* vp = papiri[i];
			if (vp->oznaka == oznaka) {
				return false; //Obveznica vec postoji. Vracamo false
			}
		}
		//vrijednosni papir s tom oznakom ne postoji
		Obveznica* o = new Obveznica(oznaka, cijena, kolicina, nominalnaCijena);
		dodajVrijednosniPapir(o);
		return true;
	}

	void LisnicaClass::toStream(ostream& to) {
		size_t kulike = papiri.size();
		to << kulike << endl;
		for (int i = 0; i < kulike; i++) {
			VrijednosniPapir *vp = papiri[i];
			vp->toStream(to);
			to << endl;
		}
	}

	void LisnicaClass::ispisToStream(ostream& to) {
		size_t kulike = papiri.size();
		to << "Sadrzaj lisnice" << endl;
		for (int i = 0; i < kulike; i++) {
			VrijednosniPapir* vp = papiri[i];
			vp->ispisToStream(to);
			to << endl;
		}
	}

	int LisnicaClass::promjenaCijene(istream& from) {
		string line;
		int promijenjeno = 0;
		while (getline(from, line)) {
			if (line.length() > 0) {
				istringstream line_stream(line);
				string oznaka;
				double novaCijena;
				line_stream >> oznaka;
				line_stream >> novaCijena;
				try {
					this->promjenaCijene(novaCijena, oznaka);
					promijenjeno++;
				}
				catch (...) {}
			}
		}
		return promijenjeno;
	}

	LisnicaClass::LisnicaClass(istream& from) : papiri() {
		int kulike;
		string line;
		from >> kulike;
		getline(from, line);
		for (int i=0; i< kulike; i++) {
			VrijednosniPapir* vp = VrijednosniPapir::fromStream(from);
			dodajVrijednosniPapir(vp);
		}
	}

	LisnicaClass::~LisnicaClass() {
		for (size_t i=0; i < this->papiri.size(); i++) {
			delete this->papiri[i];
		}
	}

}