﻿#include <iostream>
#include "LisnicaClass.h"
#include "Dionica.h"
#include "Obveznica.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <numeric> // za accumulate

namespace markot4 {
	void LisnicaClass::dodajVrijednosniPapir(VrijednosniPapir *vp){
		papiri.push_back(vp);
		return;
	}

	bool LisnicaClass::izbaciVrijednosniPapir(std::string oznaka) {

		// #algoritam koristim algoritam umjesto petlje!

		auto it = std::find_if(papiri.begin(), papiri.end(), [oznaka](VrijednosniPapir* p) {
			return p->getOznaka() == oznaka;
			});
		if (it == papiri.end()) {
			return false;
		}
		delete* it;
		papiri.erase(it);
		return true;
	}

	int LisnicaClass::promjenaKolicine(int promjena, std::string oznaka) {

		// #algoritam koristim algoritam umjesto petlje!
		auto it = std::find_if(papiri.begin(), papiri.end(), [oznaka](VrijednosniPapir* p) {
				return p->getOznaka() == oznaka;
				});
		if (it == papiri.end()) {
			throw std::invalid_argument("Ne postoji vrijednosni papir");
		}
		int novaKolicina = (*it)->dohvatiKolicinu() + promjena;
		if (novaKolicina > 0) {
			(*it)->postaviKolicinu(novaKolicina);
			return novaKolicina;
		}
		delete *it;
		papiri.erase(it);
		return 0;
	}

	// promijena cijene vrijednosnim papirima sa oznakom u varijabli "oznaka"
	void LisnicaClass::promjenaCijene(double cijena, std::string oznaka) {

		// #algoritam koristim algoritam umjesto petlje!
		auto it = std::find_if(papiri.begin(), papiri.end(), [oznaka](VrijednosniPapir* p) {
			return p->getOznaka() == oznaka;
			});
		if (it == papiri.end()) {
			throw std::invalid_argument("Ne postoji vrijednosni papir");
		}
		(*it)->postaviCijenu(cijena);
	}

	double LisnicaClass::vrijPoVrijPapir(std::string oznaka) {

		// #algoritam koristim algoritam umjesto petlje!
		auto it = std::find_if(papiri.begin(), papiri.end(), [oznaka](VrijednosniPapir* p) {
			return p->getOznaka() == oznaka;
			});
		if (it == papiri.end()) {
			return 0;
		}
		return (*it)->izracunajVrijednost();
	}

	// izračun vrijednosti svih dionica u listi papira
	double LisnicaClass::sveDionice() {

		// #algoritam koristim algoritam umjesto petlje!

		double ukupno = std::accumulate(papiri.begin(), papiri.end(), 0.0,
			[](double current_sum, VrijednosniPapir* vp) {
				if (vp->isDionica()) {
					return current_sum + vp->izracunajVrijednost();
				}
				return current_sum;
			}
		);
		return ukupno;
	}

	double LisnicaClass::sveObveznice() {

		// #algoritam koristim algoritam umjesto petlje!

		double ukupno = std::accumulate(papiri.begin(), papiri.end(), 0.0,
			[](double current_sum, VrijednosniPapir* vp) {
				if (vp->isObveznica()) {
					return current_sum + vp->izracunajVrijednost();
				}
				return current_sum;
			}
		);
		return ukupno;
	}

	double LisnicaClass::vrijednostCijeleLisnice() {
		double ukupno = sveDionice() + sveObveznice();
		return ukupno;
	}

	void LisnicaClass::sadrzajCijeleLisnice() {
		std::cout << "Sadržaj lisnice:" << std::endl;
		for (int i = 0; i < papiri.size(); i++) {
			VrijednosniPapir *vp = papiri[i];
			std::cout << "Oznaka: " << vp->getOznaka() << ", Kolicina: " << vp->dohvatiKolicinu()
				<< ", Cijena: " << vp->dohvatiCijenu() << std::endl;
		}
	}
	LisnicaClass::LisnicaClass() {
	}

	bool LisnicaClass::dodajDionicu(double cijena, int kolicina, std::string oznaka) {


		// #algoritam koristim algoritam umjesto petlje!
		auto it = std::find_if(papiri.begin(), papiri.end(), [oznaka](VrijednosniPapir *p) {
			return p->getOznaka() == oznaka;
			});
		if (it != papiri.end()) {
			return false;
		}
		// vrijednosni papir s tom oznakom ne postoji
		Dionica *d = new Dionica(oznaka, kolicina, cijena);
		dodajVrijednosniPapir(d);
		return true;
	}

	bool LisnicaClass::dodajObveznicu(std::string oznaka, double cijena, int kolicina, double nominalnaCijena) {

		// #algoritam koristim algoritam umjesto petlje!
		auto it = std::find_if(papiri.begin(), papiri.end(), [oznaka](VrijednosniPapir* p) {
			return p->getOznaka() == oznaka;
			});
		if (it != papiri.end()) {
			return false;
		}
		//vrijednosni papir s tom oznakom ne postoji
		Obveznica* o = new Obveznica(oznaka, cijena, kolicina, nominalnaCijena);
		dodajVrijednosniPapir(o);
		return true;
	}

	void LisnicaClass::toStream(std::ostream& to) {
		size_t kulike = papiri.size();
		to << kulike << std::endl;
		for (int i = 0; i < kulike; i++) {
			VrijednosniPapir *vp = papiri[i];
			vp->toStream(to);
			to << std::endl;
		}
	}

	void LisnicaClass::ispisToStream(std::ostream& to) {
		size_t kulike = papiri.size();
		to << "Sadržaj lisnice" << std::endl;
		for (int i = 0; i < kulike; i++) {
			VrijednosniPapir* vp = papiri[i];
			vp->ispisToStream(to);
			to << std::endl;
		}
	}

	int LisnicaClass::promjenaCijene(std::istream& from) {
		std::string line;
		int promijenjeno = 0;
		while (getline(from, line)) {
			if (line.length() > 0) {
				std::istringstream line_stream(line);
				std::string oznaka;
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

	LisnicaClass::LisnicaClass(std::istream& from) : papiri() {
		int kulike;
		std::string line;
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