#pragma once
#include <iostream>
#include "VrijednosniPapir.h"
#include <vector>
using namespace std;
namespace markot4 {
	class LisnicaClass
	{
	private:
		vector<VrijednosniPapir*> papiri;
		
	public:
		
		void dodajVrijednosniPapir(VrijednosniPapir *vp);
		bool izbaciVrijednosniPapir(string oznaka);
		int promjenaKolicine(int promjena, string oznaka); // vrati novu kolicinu
		void promjenaCijene(double cijena, string oznaka);
		void promjenaCijene(istream& from); // ucitava nove cijene iz streama
		double vrijPoVrijPapir(string oznaka); // vraca ukupnu vrijednost nekog papira u lisnici
		double sveDionice(); // vraca ukupnu vrijednost svih dionica u lisnici
		double sveObveznice(); // vraca ukupnu vrijednost svih obveznica u lisnici
		double vrijednostCijeleLisnice();  // vraca ukupnu vrijednost cijele lisnice
		void sadrzajCijeleLisnice(); // ispisuje sadrzaj cijele lisnice
		LisnicaClass();
		LisnicaClass(istream& from);
		bool dodajDionicu(double cijena, int kolicina, string oznaka);
		bool dodajObveznicu(string oznaka, double cijena, int kolicina, double nominalnaCijena);
		void toStream(ostream& to);
		void ispisToStream(ostream& to);

	};
}

//double vr = sveDionioce()