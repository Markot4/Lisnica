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
		int promjenaKolicine(int promjena, std::string oznaka); // vrati novu kolicinu
		void promjenaCijene(double cijena, std::string oznaka);
		int promjenaCijene(std::istream& from); // ucitava nove cijene iz streama
		double vrijPoVrijPapir(std::string oznaka); // vraca ukupnu vrijednost nekog papira u lisnici
		double sveDionice(); // vraca ukupnu vrijednost svih dionica u lisnici
		double sveObveznice(); // vraca ukupnu vrijednost svih obveznica u lisnici
		double vrijednostCijeleLisnice();  // vraca ukupnu vrijednost cijele lisnice
		void sadrzajCijeleLisnice(); // ispisuje sadrzaj cijele lisnice
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