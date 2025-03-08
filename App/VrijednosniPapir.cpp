#include <iostream>
#include "VrijednosniPapir.h"

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

	VrijednosniPapir::VrijednosniPapir(string oznaka) : oznaka(oznaka), kolicina(0), cijena(0.0) {}
	VrijednosniPapir::VrijednosniPapir(string oznaka, double cijena) : oznaka(oznaka), kolicina(0), cijena(cijena) {}

	void VrijednosniPapir::postaviCijenu(double novaCijena) {
		this->cijena = novaCijena;
	}

	double VrijednosniPapir::dohvatiCijenu() const {
		return cijena;
	}

	double VrijednosniPapir::izracunajVrijednost() {
		return kolicina * cijena;
	}
}