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

	};
}

