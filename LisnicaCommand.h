#pragma once
#include "LisnicaClass.h"

namespace markot4{
	class LisnicaCommand
	{
	private:
		int argc;
		vector<string> argv;


	public:
		LisnicaClass* lisnica;

		LisnicaCommand(int argc, const char* argv[], LisnicaClass* lisnica);
		void process();

		void vrijednostPapiraToStream(ostream& to);
		void vrijednostDionicaToStream(ostream& to);
		void vrijednostObveznicaToStream(ostream& to);
		void papiriToStream(ostream& to);
		void vrijednostLisniceToStream(ostream& to);
		void promjenaCijena(istream& from);
		void promjenaCijena(string imeDatoteke);
	};
}

