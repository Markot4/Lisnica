#include "pch.h"
#include "CppUnitTest.h"
#include "..\Dionica.h"
#include "..\Obveznica.h"
#include "..\LisnicaClass.h"
#include "..\LisnicaCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace markot4;

namespace LisnicaTest
{
	TEST_CLASS(LisnicaTest)
	{
	public:

		TEST_METHOD(izbacivanjeVrijednosnogpapira)
		{
			// 1. moram imati lisnicu
			// 2. mkoram potrpati, vise vrijednosnih papira u tu lisnicu (3,4)
			// 3. izbacim jedan od tihg vrijednosnih papira
			// 4. provjerim da li je dobro izbacen taj vrijednosni papir (recimo mogu provjeriti novu vrijednost lisnice)
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(13.00, 24, "Yolo");
			l->dodajDionicu(26.00, 12, "Imbecil");
			l->dodajDionicu(39.00, 6, "Ultra");
			l->izbaciVrijednosniPapir("Ultra");
			double rez = l->sveDionice();
			Assert::AreEqual(rez, 624.00);

		}

		TEST_METHOD(promjenaCijene)
		{
			//moram imati lisnicu u kojoj ce biti vise vrijednosnih papira. 
			//moram promijeniti cijenu u jednom od tih vrijednosnih papira i provjeriti
			//da li je cijena dobro promijenjena
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(14.99, 25, "Wazap");
			l->dodajDionicu(25.00, 60, "Yo");
			l->promjenaCijene(20.00, "Wazap");
			// provjeriti da li je vrijednoist svih dionica u lisnici jednaka 2000
			double rez = l->sveDionice();
			Assert::AreEqual(rez, 2000.00);
		}

		TEST_METHOD(promjenaKolicine)
		{
			//moram imati lisnicu u kojoj ce biti vise vrijednosnih papira. 
			//moram promijeniti cijenu u jednom od tih vrijednosnih papira i provjeriti
			//da li je kolicina dobro promijenjena
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(10.00, 25, "Wazap");
			l->dodajDionicu(20.00, 60, "Yo");
			l->promjenaKolicine(15, "Wazap");
			// provjeriti da li je vrijednoist svih dionica u lisnici jednaka 1600
			double rez = l->sveDionice();
			Assert::AreEqual(rez, 1600.0);
		}

		TEST_METHOD(smanjenjeKolicine)
		{
			//otkad promjenaKolicine povecava broj kolicina dionice, ova test metoda smanjuje
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(12.00, 12, "Ula");
			l->dodajDionicu(10.00, 10, "Eli");
			l->promjenaKolicine(-2, "Ula");
			double rez = l->sveDionice();
			Assert::AreEqual(rez, 220.0);
		}

		TEST_METHOD(smanjenjeKolicine2)
		{
			//otkad promjenaKolicine povecava broj kolicina dionice, ova test metoda smanjuje
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(12.00, 12, "Ula");
			l->dodajDionicu(10.00, 10, "Eli");
			l->promjenaKolicine(-12, "Eli");
			double rez = l->sveDionice();
			Assert::AreEqual(rez, 144.0);
		}

		TEST_METHOD(vrijednostCijeleLisnice)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(24.50, 21, "Gog");
			l->dodajObveznicu("Steam", 12.00, 14, 15.00);
			double rez = l->vrijednostCijeleLisnice();
			Assert::AreEqual(rez, 539.7, 0.1);
		}

		/*TEST_METHOD(sadrzajCijeleLisnice)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(15.50, 14, "Hobit");
			string rez = l->sadrzajCijeleLisnice();
			string ocekivano = "Oznaka Hobit Kolicina 14 Cijena 15.50";
			Assert::AreEqual(ocekivano, rez);
		}*/

		TEST_METHOD(LeesnicatoStrum)
		{
			//trebam stream u kojem cu pisati
			//trebam lisnicu
			//u lisnicu moram barem staviti jednu dionicu i jednu obveznicu
			//pozvati toStream na lisnici
			//provjeriti da li su se dionica i obveznica dobro ispisali
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(19.50, 25, "Veku");
			l->dodajObveznicu("Gogeta", 20.00, 30, 21.00);
			ostringstream out;
			l->toStream(out);
			string rez = out.str();
			string expected = "2\ndionica Veku 19.50 25\nobveznica Gogeta 20.00 30 21.00\n";
			Assert::AreEqual(expected, rez);
		}

		TEST_METHOD(LeesnicatoStrum2)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(15.00, 30, "Fallout");
			l->dodajDionicu(17.50, 35, "Stalker");
			l->dodajObveznicu("Condemned", 20.00, 40, 21.00);
			l->dodajObveznicu("Hitman", 22.50, 45, 22.00);
			ostringstream out;
			l->toStream(out);
			string rez = out.str();
			string expected = "4\ndionica Fallout 15.00 30\ndionica Stalker 17.50 35\nobveznica Condemned 20.00 40 21.00\nobveznica Hitman 22.50 45 22.00\n";
			Assert::AreEqual(expected, rez);
		}

		TEST_METHOD(VrijednosniPapirFromStream)
		{
			//trebam varijablu tipa pointer na vrijednosnipapir
			//trebam pozvati staticku metodu fromStream na klasi VrijednosniPapir sa podacima za dionicu
			//nakon toga provjeriti da je VrijednosniPapir dobro kreiran
			istringstream in = istringstream("dionica Dawg 13.60 95");
			VrijednosniPapir* vp = VrijednosniPapir::fromStream(in);
			Assert::IsTrue(vp->isDionica());
			Assert::IsFalse(vp->isObveznica());
			Assert::AreEqual(vp->oznaka, string("Dawg"));
			Assert::AreEqual(vp->cijena, 13.60);
			Assert::AreEqual(vp->kolicina, 95);
		}

		TEST_METHOD(VrijednosniPapirFromStream2)
		{
			//trebam varijablu tipa pointer na vrijednosnipapir
			//trebam pozvati staticku metodu fromStream na klasi VrijednosniPapir sa podacima za obveznicu
			//nakon toga provjeriti da je VrijednosniPapir dobro kreiran
			istringstream in = istringstream("obveznica Birdy 15.00 75 20.00");
			VrijednosniPapir* vp = VrijednosniPapir::fromStream(in);
			Assert::IsTrue(vp->isObveznica());
			Assert::IsFalse(vp->isDionica());
			Assert::AreEqual(vp->oznaka, string("Birdy"));
			Assert::AreEqual(vp->cijena, 15.00);
			Assert::AreEqual(vp->kolicina, 75);
			Assert::AreEqual(((Obveznica*)vp)->nominalnaCijena, 20.00);
		}

		TEST_METHOD(LisnicaFromStream)
		{
			istringstream in = istringstream("2\ndionica Veku 19.50 25\nobveznica Gogeta 20.00 30 21.00\n");
			LisnicaClass* lisnica = new LisnicaClass(in);
			Assert::AreEqual(lisnica->sveDionice(), 487.5);
			Assert::AreEqual(lisnica->sveObveznice(), 126.0);
			Assert::AreEqual(lisnica->vrijednostCijeleLisnice(), 613.5);
		}

		TEST_METHOD(TestDionicaIme)
		{
			Dionica d("PL-V-A", 107, 13.2);
			std::string ocekivano = "PL-V-A";
			Assert::AreEqual(ocekivano, d.oznaka);
		}

		TEST_METHOD(TestDionicaCijena)
		{
			Dionica d("PL-V-A", 105, 12.3);
			Assert::AreEqual(12.3, d.cijena);
		}

		TEST_METHOD(TestDionicaKolicina)
		{
			Dionica d("PL-V-A", 107, 12.1);
			Assert::AreEqual(107, d.kolicina);
		}

		TEST_METHOD(TestDionicaVrijednost)
		{
			Dionica d("PL-V-A", 107, 12.3);
			Assert::AreEqual(d.izracunajVrijednost(), 107 * 12.3);
		}

		TEST_METHOD(DionicatoStream)
		{
			Dionica d("Dawg", 95, 13.60);
			ostringstream out;
			d.toStream(out);
			string rez = out.str();
			string expected = "dionica Dawg 13.60 95";
			Assert::AreEqual(expected, rez);
		}

		TEST_METHOD(DionicaFromStream)
		{
			istringstream stream = istringstream("Dawg 13.60 95");
			Dionica d(stream);
			Assert::AreEqual(d.kolicina, 95);
			Assert::AreEqual(d.cijena, 13.60);
			string expected = "Dawg";
			Assert::AreEqual(d.oznaka, expected);
		}

		TEST_METHOD(TestDionicaisDionica)
		{
			Dionica d("PL-V-A", 107, 12.3);
			Assert::AreEqual(d.isDionica(), true);
		}

		TEST_METHOD(TestDionicaisObveznica)
		{
			Dionica d("PL-V-A", 107, 12.3);
			Assert::AreEqual(d.isObveznica(), false);
		}

		TEST_METHOD(dodajDionicu)
		{
			LisnicaClass* l = new LisnicaClass();
			double c = 73.18;
			l->dodajDionicu(c, 100, "Fatman");
		}

		TEST_METHOD(sveDionice)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(14.99, 25, "Wazap");
			l->dodajDionicu(29.98, 50, "Yo");
			l->dodajObveznicu("Hoker", 42.56, 91, 70.38);
			double rez = l->sveDionice();
			Assert::AreEqual(rez, 1873.75);
		}

		TEST_METHOD(vracanjeukupneVrijednostiDionice)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajDionicu(12.00, 40, "Funky");
			double rez = l->vrijPoVrijPapir("Funky");
			Assert::AreEqual(rez, 480.00);
		}

		TEST_METHOD(vracanjeukupneVrijednostiDionice2)
		{
			LisnicaClass* l = new LisnicaClass();
			double rez = l->vrijPoVrijPapir("Funky");
			Assert::AreEqual(rez, 0.00);
		}

		TEST_METHOD(DionicaToFromStream)
		{
			// napravi dionicu
			// spremi dionicu u stream
			// iz tog streama procitaj novu dionicu
			// usporedi da li su podaci u pocetnoj i novoj dionici isti (oznaka, kolicina, cijena)

			Dionica d("Stup", 20, 15.20);
			ostringstream out;
			d.toStream(out);
			string rez = out.str();
			istringstream in = istringstream(rez);
			string vrsta;
			in >> vrsta;
			string vrstaDionica = "dionica";
			Assert::AreEqual(vrsta, vrstaDionica);
			Dionica nova(in);
			Assert::AreEqual(d.oznaka, nova.oznaka);
			Assert::AreEqual(d.kolicina, nova.kolicina);
			Assert::AreEqual(d.cijena, nova.cijena);
		}
		TEST_METHOD(TestObveznicaIme)
		{
			Obveznica o("PL-A", 94, 5, 12.5);
			std::string ocekivano = "PL-A";
			Assert::AreEqual(ocekivano, o.oznaka);
		}

		TEST_METHOD(TestObveznicaCijena)
		{
			Obveznica o("PL-A", 94.2, 5, 12.5);
			Assert::AreEqual(94.2, o.cijena);
		}

		TEST_METHOD(TestObveznicaKolicina)
		{
			Obveznica o("PL-A", 94, 5, 12.5);
			Assert::AreEqual(5, o.kolicina);
		}

		TEST_METHOD(TestObveznicaNominalnaCijena)
		{
			Obveznica o("PL-A", 94, 5, 12.5);
			Assert::AreEqual(12.5, o.nominalnaCijena);
		}

		TEST_METHOD(TestObveznicaVrijednost)
		{
			Obveznica o("PL-A", 94, 5, 12.5);
			Assert::AreEqual(o.izracunajVrijednost(), 94 * 12.5 * 5 / 100);
		}

		TEST_METHOD(TestObveznicaisObveznica)
		{
			Obveznica o("PL-V-A", 107, 5, 12.3);
			Assert::AreEqual(o.isObveznica(), true);
		}

		TEST_METHOD(TestObveznicaisDionica)
		{
			Obveznica o("PL-V-A", 107, 5, 12.3);
			Assert::AreEqual(o.isDionica(), false);
		}

		TEST_METHOD(dodajObveznicu)
		{
			LisnicaClass* l = new LisnicaClass();
			double c = 73.18;
			bool t = l->dodajObveznicu("Fatman", c, 100, 53.12);
			Assert::AreEqual(t, true);
		}

		TEST_METHOD(nedodajIstoime)
		{
			LisnicaClass* l = new LisnicaClass();
			bool e = l->dodajObveznicu("Duplic", 100.00, 10, 100.00);
			bool t = l->dodajObveznicu("Duplic", 50.00, 20, 50.00);
			Assert::AreEqual(t, false);
		}

		TEST_METHOD(sveObveznice)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajObveznicu("Fatman", 73.18, 100, 53.12);
			l->dodajObveznicu("Robin", 42.56, 91, 70.38);
			l->dodajDionicu(19.99, 20, "PoS");
			double rez = l->sveObveznice();
			Assert::AreEqual(rez, 6613.110848);
		}
		TEST_METHOD(ObveznicatoStream)
		{
			Obveznica d("Fatman", 73.18, 100, 53.12);
			ostringstream out;
			d.toStream(out);
			string rez = out.str();
			string expected = "obveznica Fatman 73.18 100 53.12";
			Assert::AreEqual(expected, rez);
		}

		TEST_METHOD(vrijednostObveznice)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajObveznicu("Faku", 20.00, 24, 28.32);
			double rez = l->sveObveznice();
			Assert::AreEqual(rez, 135.936, 0.001);
		}

		TEST_METHOD(vracanjeukupneVrijednostiObveznice)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajObveznicu("Diarrhea", 15.00, 40, 20.00);
			double rez = l->vrijPoVrijPapir("Diarrhea");
			Assert::AreEqual(rez, 120.00, 0.01);
		}

		TEST_METHOD(vracanjeukupneVrijednostiObveznice2)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajObveznicu("Fool", 20.00, 40, 30.00);
			double rez = l->vrijPoVrijPapir("Fool");
			Assert::AreEqual(rez, 240.00, 0.01);
		}

		TEST_METHOD(ObveznicaFromStream) {
			istringstream stream = istringstream("Binch 15.20 20 16.00");
			Obveznica o(stream);
			Assert::AreEqual(o.nominalnaCijena, 16.00);
			Assert::AreEqual(o.kolicina, 20);
			Assert::AreEqual(o.cijena, 15.20);
			string expected = "Binch";
			Assert::AreEqual(o.oznaka, expected);
		}

		TEST_METHOD(ObveznicaToFromStream) {
			// napravi obveznicu
			// spremi obveznicu u stream
			// iz tog streama procitaj novu obveznicu
			// usporedi da li su podaci u pocetnoj i novoj obveznici isti (oznaka, cijena, kolicina, nominala)
			Obveznica o("World", 12.00, 24, 17.00);
			ostringstream out;
			o.toStream(out);
			string rez = out.str();
			istringstream in = istringstream(rez);
			string vrsta;
			in >> vrsta;
			string vrstaObveznica = "obveznica";
			Assert::AreEqual(vrsta, vrstaObveznica);
			Obveznica nova(in);
			Assert::AreEqual(o.oznaka, nova.oznaka);
			Assert::AreEqual(o.kolicina, nova.kolicina);
			Assert::AreEqual(o.cijena, nova.cijena);
			Assert::AreEqual(o.nominalnaCijena, nova.nominalnaCijena);
		}

		TEST_METHOD(lisnicaCommandConstructor)
		{
			const char* argv[] = { "program_name", "arg1", "arg2", "arg3" };
			LisnicaClass* l = new LisnicaClass();
			LisnicaCommand lc(4, argv, l);
		}

		TEST_METHOD(lisnicaCommanddodajDionica)
		{
			// treba mi lisnica, i lisnica command
			// trebam testirati komandu: lisnica dodaj dionica RIMAC 100 16.92
			LisnicaClass* l = new LisnicaClass();
			const char* argv[] = { "Lisnica", "dodaj", "dionica", "RIMAC", "100", "16.92" };
			LisnicaCommand lc(6, argv, l);
			lc.process();
			double vrijednost = l->vrijednostCijeleLisnice();
			Assert::AreEqual(vrijednost, 1692.00, 0.01);
		}

		TEST_METHOD(lisnicaCommanddodajDionica2)
		{
			// testiranje pogresnog broja parametara
			try {
				LisnicaClass* l = new LisnicaClass();
				const char* argv[] = { "Lisnica", "dodaj", "dionica", "RIMAC", "100", "16.92" };
				LisnicaCommand lc(5, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(lisnicaCommanddodajDionica3)
		{
			// testiranje pogresnog broja parametara
			try {
				LisnicaClass* l = new LisnicaClass();
				const char* argv[] = { "Lisnica", "dodaj", "dionica", "RIMAC", "100", "16.92", "siljispiljis" };
				LisnicaCommand lc(7, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(lisnicaCommanddodajDionica4)
		{
			// treba mi lisnica, i lisnica command
			// trebam testirati komandu: lisnica dodaj dionica RIMAC 100 16.92
			try {
				LisnicaClass* l = new LisnicaClass();
				const char* argv[] = { "Lisnica", "dodaj", "dionica", "RIMAC", "Bitch", "16.92", "siljispiljis" };
				LisnicaCommand lc(7, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(lisnicaCommanddodajObveznica)
		{
			LisnicaClass* l = new LisnicaClass();
			const char* argv[] = { "Lisnica", "dodaj", "obveznica", "PLIVA", "40", "57.00", "45.21" };
			LisnicaCommand lc(7, argv, l);
			lc.process();
			double vrijednost = l->vrijednostCijeleLisnice();
			Assert::AreEqual(vrijednost, 1030.788, 0.001);
		}

		TEST_METHOD(lisnicaCommanddodajObveznica2)
		{
			try {
				LisnicaClass* l = new LisnicaClass();
				const char* argv[] = { "Lisnica", "dodaj", "obveznica", "PLIVA", "40", "57.00", "45.21" };
				LisnicaCommand lc(6, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(komandaizbacivanjeVrijednosnogpapira)
		{
			// napraviti lisnicu, dodati dva vrijednsna papira
			// napraviti lisnica command s argv za brisanje
			// provjeriti da li je vp izbacen - vrijednost lisnice vise ga ne smije ukljucivati
			LisnicaClass* l = new LisnicaClass();
			bool o = l->dodajObveznicu("Thin", 20.00, 24, 19.00);
			bool d = l->dodajDionicu(42.00, 60, "Muscular");
			const char* argv[] = { "Lisnica", "izbaci", "Thin" };
			LisnicaCommand lc(3, argv, l);
			lc.process();
			double vrijednost = l->vrijednostCijeleLisnice();
			Assert::AreEqual(vrijednost, 2520.00, 0.01);
		}

		TEST_METHOD(TestKomandaIzbacivanjeVPKrivibrojargumenata)
		{
			LisnicaClass* l = new LisnicaClass();
			const char* argv[] = { "lisnica", "dodaj" };
			try
			{
				LisnicaCommand lc(2, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(BrisiDionicukojenema)
		{
			LisnicaClass* l = new LisnicaClass();
			const char* argv[] = {"lisnica", "izbaci", "Brap"};
			try 
			{
				LisnicaCommand lc(3, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			} catch(...){}
		}

		TEST_METHOD(PostojeciPapir)
		{
			LisnicaClass* l = new LisnicaClass();
			bool o = l->dodajObveznicu("Ninjer", 42.00, 36, 24.00);
			const char* argv[] = { "Lisnica", "dodaj", "obveznica", "Ninjer", "42.00", "36", "24.00"};
			try
			{
				LisnicaCommand lc(7, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...){}
		}

		TEST_METHOD(PostojeciPapir2)
		{
			LisnicaClass* l = new LisnicaClass();
			bool d = l->dodajDionicu(24.00, 12, "Binch");
			const char* argv[] = {"Lisnica", "dodaj", "obveznica", "Ninjer", "24.00", "12"};
			try
			{
				LisnicaCommand lc(6, argv, l);
				lc.process();
				Assert::Fail(L"Expeceted an exception but none was thrown.");
			}
			catch(...){}
		}

		TEST_METHOD(lisnicaClassPromjenaKolicine)
		{
			LisnicaClass* l = new LisnicaClass();
			bool d = l->dodajDionicu(24.00, 12, "Binch");
			const char* argv[] = {"lisnica", "kolicina", "Binch", "20"};
			LisnicaCommand lc(4, argv, l);
			lc.process();
			double vrijednost = l->vrijednostCijeleLisnice();
			Assert::AreEqual(vrijednost, 768.00, 0.01);
		}

		TEST_METHOD(lisnicaClassPromjenaKolicine2)
		{
			LisnicaClass* l = new LisnicaClass();
			bool d = l->dodajDionicu(24.00, 12, "Binch");
			const char* argv[] = { "lisnica", "kolicina", "Banch", "20" };
			try
			{
				LisnicaCommand lc(4, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch(...){}
		}

		TEST_METHOD(lisnicaClassPromjenaKolicine3)
		{
			LisnicaClass* l = new LisnicaClass();
			bool d = l->dodajDionicu(24.00, 12, "Binch");
			const char* argv[] = { "lisnica", "kolicina", "Binch", "20", "12"};
			try
			{
				LisnicaCommand lc(5, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(lisnicaClassPromjenaCijene)
		{
			LisnicaClass* l = new LisnicaClass();
			bool o = l->dodajObveznicu("Wroom", 50.00, 20, 24.00);
			const char* argv[] = { "lisnica", "cijena", "Wroom", "20.00"};
			LisnicaCommand lc(4, argv, l);
			lc.process();
			double vrijednost = l->vrijednostCijeleLisnice();
			Assert::AreEqual(vrijednost, 96.00, 0.01);
		}

		TEST_METHOD(lisnicaClassPromjenaCijene2)
		{
			LisnicaClass* l = new LisnicaClass();
			bool o = l->dodajObveznicu("Wroom", 50.00, 20, 24.00);
			const char* argv[] = { "lisnica", "cijena", "Broom", "20.00" };
			try
			{
				LisnicaCommand lc(4, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...){}
		}

		TEST_METHOD(lisnicaClassPromjenaCijene3)
		{
			LisnicaClass* l = new LisnicaClass();
			bool o = l->dodajObveznicu("Wroom", 50.00, 20, 24.00);
			const char* argv[] = { "lisnica", "cijena", "Broom", "20.00", "30.00"};
			try
			{
				LisnicaCommand lc(5, argv, l);
				lc.process();
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(ispisVrijednostiPapira)
		{
			LisnicaClass* l = new LisnicaClass();
			bool o = l->dodajDionicu(20.00, 25, "PLIVA");
			const char* argv[] = { "lisnica", "vrijednost", "PLIVA"};
			LisnicaCommand lc(3, argv, l);
			ostringstream out;
			lc.vrijednostPapiraToStream(out);
			string rez = out.str();
			Assert::AreEqual(rez, string("Vrijednost PLIVA je 500.00 Eur"));
		}
		
		TEST_METHOD(IspisUkupneVrijednostiDionica)
		{
			LisnicaClass* l = new LisnicaClass();
			bool d1 = l->dodajDionicu(10.00, 10, "Warcraft 4");
			bool d2 = l->dodajDionicu(20.00, 15, "Gran Turismo 8");
			bool o1 = l->dodajObveznicu("Meridianus", 10.00, 15, 12.00);
			const char* argv[] = { "lisnica", "vrijednost", "dionice"};
			LisnicaCommand lc(3, argv, l);
			ostringstream out;
			lc.vrijednostDionicaToStream(out);
			string rez = out.str();
			Assert::AreEqual(rez, string("Ukupna vrijednost svih dionica u lisnici je 400.00 Eur"));
			
		}

		TEST_METHOD(IspisUkupneVrijednostiDionica2)
		{
			LisnicaClass* l = new LisnicaClass();
			bool d1 = l->dodajDionicu(0.00, 10, "Warcraft 4");
			bool d2 = l->dodajDionicu(0.00, 15, "Gran Turismo 8");
			bool o1 = l->dodajObveznicu("Meridianus", 10.00, 15, 12.00);
			const char* argv[] = { "lisnica", "vrijednost", "dionice", "15.00"};
			try
			{
				LisnicaCommand lc(4, argv, l);
				ostringstream out;
				lc.vrijednostDionicaToStream(out);
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(IspisUkupneVrijednostiObveznica)
		{
			LisnicaClass* l = new LisnicaClass();
			bool o1 = l->dodajObveznicu("Meridianus", 10.00, 15, 12.00);
			bool o2 = l->dodajObveznicu("2000 Miles", 12.00, 19, 14.00);
			bool d1 = l->dodajDionicu(0.00, 10, "Warcraft 4");
			const char* argv[] = { "lisnica", "vrijednost", "obveznice" };
			LisnicaCommand lc(3, argv, l);
			ostringstream out;
			lc.vrijednostObveznicaToStream(out);
			string rez = out.str();
			Assert::AreEqual(rez, string("Ukupna vrijednost svih obveznica u lisnici je 49.92 Eur"));

		}

		TEST_METHOD(IspisUkupneVrijednostiObveznica2)
		{
			LisnicaClass* l = new LisnicaClass();
			bool o1 = l->dodajObveznicu("Meridianus", 10.00, 15, 12.00);
			bool o2 = l->dodajObveznicu("2000 Miles", 12.00, 19, 14.00);
			bool d1 = l->dodajDionicu(0.00, 10, "Warcraft 4");
			const char* argv[] = { "lisnica", "vrijednost", "obveznice", "16.00"};
			try {
				LisnicaCommand lc(4, argv, l);
				ostringstream out;
				lc.vrijednostObveznicaToStream(out);
				Assert::Fail(L"Expected an exception but none was thrown.");
			}
			catch (...) {}
		}

		TEST_METHOD(papiriToStream)
		{
			LisnicaClass* l = new LisnicaClass();
			bool o1 = l->dodajObveznicu("Wanky", 15.00, 10, 14.00);
			bool o2 = l->dodajObveznicu("KilE", 12.00, 11, 13.00);
			bool d1 = l->dodajDionicu(5.00, 1, "PaySt");
			bool d2 = l->dodajDionicu(6.00, 2, "ThrOg");
			const char* argv[] = { "lisnica", "sadrzaj"};
			LisnicaCommand lc(2, argv, l);
			ostringstream out;
			lc.papiriToStream(out);
			string rez = out.str();
			Assert::AreEqual(rez, string("Sadrzaj lisnice\nWanky 15.00 10 14.00\nKilE 12.00 11 13.00\nPaySt 5.00 1\nThrOg 6.00 2\n"));
		}
	};

}

