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
		
		TEST_METHOD(TestObveznica)
		{
			Obveznica o("PL-A", 94, 5, 12.5);
			Assert::AreEqual(94.0, o.cijena);
			std::string ocekivano = "PL-A";
			Assert::AreEqual(ocekivano, o.oznaka);
		}
	
	};
}

