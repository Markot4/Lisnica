#include <iostream>
#include "VrijednosniPapir.h"
#include "Dionica.h"
#include "Obveznica.h"

namespace markot4 {

	/*
	IDEJA:
		napraviti klasu VrijednosniPapir abstraktnom postavljajuci joj metode kao virtualne
		omoguciti polimorfizam i dinamicko castanje tipova
	
	ILI:
		izbrisati klase Dionica i Obveznica jer nemaju nikakvu dodatnu funkcionalnost u odnosu na roditeljsku
		klasu VrijednosniPapir
		dodatni dodatnu privatnu varijablu u klasu VrijednosniPapir koja oznacava o kojem tipu vrijednosnog
		papira se radi (obveznica ili dionica)
	*/

	VrijednosniPapir::VrijednosniPapir() : oznaka(""), kolicina(0), cijena(0.0) {}
	VrijednosniPapir::VrijednosniPapir(string oznaka) : oznaka(oznaka), kolicina(0), cijena(0.0) {}
	VrijednosniPapir::VrijednosniPapir(string oznaka, int kolicina, double cijena) : oznaka(oznaka), kolicina(kolicina), cijena(cijena) {}

	VrijednosniPapir* VrijednosniPapir::fromStream(istream& from) {
		string vrsta;
		from >> vrsta;
		if (vrsta == "dionica") {
			return new Dionica(from);
		}
		if (vrsta != "obveznica") {
			throw invalid_argument("Nepostojeća vrsta vrijednosnog papira");
		}
		return new Obveznica(from);
	}

	void VrijednosniPapir::postaviCijenu(double novaCijena) {
		this->cijena = novaCijena;
	}

	double VrijednosniPapir::dohvatiCijenu() const {
		return cijena;
	}

	VrijednosniPapir::~VrijednosniPapir() {

	}


}