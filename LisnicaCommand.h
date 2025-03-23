#pragma once
#include "LisnicaClass.h"

namespace markot4{
	class LisnicaCommand
	{
	private:
		int argc;
		vector<string> argv;
		LisnicaClass* lisnica;


	public:
		LisnicaCommand(int argc, char* argv[]);
		void process();

	};
}

