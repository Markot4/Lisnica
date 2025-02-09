#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace markot4 {

	// vrijednosi papir moze biti dionica ili obveznica
	// vrijednosti papir je roditeljska klasa tim dviju klasama
	class VrijednosniPapir {
	public:
		double cijena; 
		int kolicina;
		string oznaka;

        VrijednosniPapir(string oznaka);
		VrijednosniPapir(string oznaka, double cijena);

		void postaviCijenu(double novaCijena); 
		double dohvatiCijenu() const;
		double izracunajVrijednost();
	};
}