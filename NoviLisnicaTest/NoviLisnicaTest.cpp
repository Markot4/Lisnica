#include "pch.h"
#include "CppUnitTest.h"
#include "..\Dionica.h"
#include "..\Obveznica.h"
#include "..\LisnicaClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace markot4;

namespace LisnicaTest
{
	TEST_CLASS(LisnicaTest)
	{
	public:

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
			Assert::AreEqual(d.izracunajVrijednost() ,  107 * 12.3);
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
		
		TEST_METHOD(vrijednostObveznice)
		{
			LisnicaClass* l = new LisnicaClass();
			l->dodajObveznicu("Faku", 20.00, 24, 28.32);
			double rez = l->sveObveznice();
			Assert::AreEqual(rez, 135.936,0.001);
		}
	};
}

