#pragma once
#include "LisnicaClass.h"

namespace markot4{
	class LisnicaCommand
	{
	private:
		int argc;
		std::vector<std::string> argv;


	public:
		LisnicaClass* lisnica;

		LisnicaCommand(int argc, const char* argv[], LisnicaClass* lisnica);
		void process();

		void vrijednostPapiraToStream(std::ostream& to);
		void vrijednostDionicaToStream(std::ostream& to);
		void vrijednostObveznicaToStream(std::ostream& to);
		void papiriToStream(std::ostream& to);
		void vrijednostLisniceToStream(std::ostream& to);
		void promjenaCijena(std::istream& from);
		void promjenaCijena(std::string imeDatoteke);

	};
}

