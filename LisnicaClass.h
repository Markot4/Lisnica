#pragma once
#include <iostream>
#include "VrijednosniPapir.h"
#include <vector>
namespace markot4 {
	class LisnicaClass
	{
	private:
		std::vector<VrijednosniPapir*> papiri;
		
	public:
		
		void dodajVrijednosniPapir(VrijednosniPapir *vp);
		bool izbaciVrijednosniPapir(std::string oznaka);
		int promjenaKolicine(int promjena, std::string oznaka); // vrati novu količinu
		void promjenaCijene(double cijena, std::string oznaka);
		int promjenaCijene(std::istream& from); // učitava nove cijene iz streama
		double vrijPoVrijPapir(std::string oznaka); // vraća ukupnu vrijednost nekog papira u lisnici
		double sveDionice(); // vraća ukupnu vrijednost svih dionica u lisnici
		double sveObveznice(); // vraća ukupnu vrijednost svih obveznica u lisnici
		double vrijednostCijeleLisnice();  // vraća ukupnu vrijednost cijele lisnice
		void sadrzajCijeleLisnice(); // ispisuje sadržaj cijele lisnice
		LisnicaClass();
		LisnicaClass(std::istream& from);
		bool dodajDionicu(double cijena, int kolicina, std::string oznaka);
		bool dodajObveznicu(std::string oznaka, double cijena, int kolicina, double nominalnaCijena);
		void toStream(std::ostream& to);
		void ispisToStream(std::ostream& to);

		~LisnicaClass();


	};
}

//double vr = sveDionioce()