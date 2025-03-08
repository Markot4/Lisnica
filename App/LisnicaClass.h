#pragma once
#include <iostream>
#include "VrijednosniPapir.h"
#include <vector>
using namespace std;
namespace markot4 {
	class LisnicaClass
	{
	private:
		vector<VrijednosniPapir> papiri;
		
	public:
		
		void dodajVrijednosniPapir(VrijednosniPapir vp);
		void izbaciVrijednosniPapir(string oznaka);
		int promjenaKolicine(int promjena, string oznaka); // vrati novu kolicinu
		void promjenaCijene(double cijena, string oznaka);
		int promjenaCijene(string paragraf); // parametar paragraf predstavlja ime datoteke iz koje se citaju cijene
		//funkcija vraca broj vrijednosnih papira cija se cijena promijenila
		double vrijPoVrijPapir(string oznaka); // vraca ukupnu vrijednost nekog papira u lisnici
		double sveDionice(); // vraca ukupnu vrijednost svih dionica u lisnici
		double sveObveznice(); // vraca ukupnu vrijednost svih obveznica u lisnici
		double vrijednostCijeleLisnice();  // vraca ukupnu vrijednost cijele lisnice
		void sadrzajCijeleLisnice(); // ispisuje sadrzaj cijele lisnice
		LisnicaClass();
	};
}

//double vr = sveDionioce()