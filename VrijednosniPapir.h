#pragma once
#include <iostream>
#include <string>
//using namespace std;

namespace markot4 {

	// vrijednosni papir moze biti dionica ili obveznica
	// vrijednosni papir je roditeljska klasa tim dviju klasama
	class VrijednosniPapir {
	public:
		double cijena; 
		int kolicina;
		std::string oznaka;

		VrijednosniPapir();
		VrijednosniPapir(std::string oznaka);
		VrijednosniPapir(std::string oznaka, int kolicina, double cijena);

		VrijednosniPapir(const VrijednosniPapir&) = delete;
		VrijednosniPapir& operator=(const VrijednosniPapir&) = delete;
		VrijednosniPapir(VrijednosniPapir&&) = delete;
		VrijednosniPapir& operator=(VrijednosniPapir&&) = delete;

		static VrijednosniPapir* fromStream(std::istream& from);

		void postaviCijenu(double novaCijena); 
		double dohvatiCijenu() const;
		virtual double izracunajVrijednost() = 0;
		virtual bool isDionica() = 0;
		virtual bool isObveznica() = 0;
		virtual void toStream(std::ostream &to) = 0;
		virtual void ispisToStream(std::ostream& to) = 0;
		virtual ~VrijednosniPapir();
	};
}