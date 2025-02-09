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

		TEST_METHOD(TestDionica)
		{
			Dionica d("PL-V-A", 107);
			Assert::AreEqual(107.0, d.cijena);
			std::string ocekivano = "PL-V-A";
			Assert::AreEqual(ocekivano, d.oznaka);
		}
		
		TEST_METHOD(TestObveznica)
		{
			Obveznica o("PL-A", 94);
			Assert::AreEqual(94.0, o.cijena);
			std::string ocekivano = "PL-A";
			Assert::AreEqual(ocekivano, o.oznaka);
		}
		

	};
}

