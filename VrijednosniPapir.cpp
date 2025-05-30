﻿#include <iostream>
#include "VrijednosniPapir.h"
#include "Dionica.h"
#include "Obveznica.h"

namespace markot4 {

	/*
	IDEJA:
		napraviti klasu VrijednosniPapir abstraktnom postavljajući joj metode kao virtualne
		omogućiti polimorfizam i dinamicko castanje tipova
	
	ILI:
		izbrisati klase Dionica i Obveznica jer nemaju nikakvu dodatnu funkcionalnost u odnosu na roditeljsku
		klasu VrijednosniPapir
		dodatni dodatnu privatnu varijablu u klasu VrijednosniPapir koja označava o kojem tipu vrijednosnog
		papira se radi (obveznica ili dionica)
	*/

	VrijednosniPapir::VrijednosniPapir() : oznaka(""), kolicina(0), cijena(0.0) {}
	VrijednosniPapir::VrijednosniPapir(std::string oznaka) : oznaka(oznaka), kolicina(0), cijena(0.0) {}
	VrijednosniPapir::VrijednosniPapir(std::string oznaka, int kolicina, double cijena) : oznaka(oznaka), kolicina(kolicina), cijena(cijena) {}

	VrijednosniPapir* VrijednosniPapir::fromStream(std::istream& from) {
		std::string vrsta;
		from >> vrsta;
		if (vrsta == "dionica") {
			return new Dionica(from);
		}
		if (vrsta != "obveznica") {
			throw std::invalid_argument("Nepostojeća vrsta vrijednosnog papira");
		}
		return new Obveznica(from);
	}

	std::string& VrijednosniPapir::getOznaka()  {
		return this->oznaka;
	}

	void VrijednosniPapir::postaviCijenu(double novaCijena) {
		this->cijena = novaCijena;
	}

	double VrijednosniPapir::dohvatiCijenu() const {
		return cijena;
	}
	void VrijednosniPapir::postaviKolicinu(int novaKolicina) {
		this->kolicina = novaKolicina;
	}
	int VrijednosniPapir::dohvatiKolicinu() const {
		return kolicina;
	}
	VrijednosniPapir::~VrijednosniPapir() {

	}


}