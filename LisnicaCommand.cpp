#include "LisnicaCommand.h"

namespace markot4 {
	LisnicaCommand::LisnicaCommand(int argc, const char* argv[], LisnicaClass* lisnica) {
			this->lisnica = lisnica;
		this->argc = argc;
		for (int i = 0; i < argc; ++i) {
			this->argv.push_back(std::string(argv[i]));  // Convert char* to std::string and add to vector
		}
	}
	void LisnicaCommand::process() {

	}
}