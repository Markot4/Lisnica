#include "LisnicaCommand.h"
#include <stdexcept>

namespace markot4 {
	LisnicaCommand::LisnicaCommand(int argc, const char* argv[], LisnicaClass* lisnica) {
			this->lisnica = lisnica;
		this->argc = argc;
		for (int i = 0; i < argc; ++i) {
			this->argv.push_back(std::string(argv[i]));  // Convert char* to std::string and add to vector
		}
	}

	void LisnicaCommand::process() {
        argc = this->argc;
        string naredba = this->argv[1];

        if (naredba == "dodaj" && argc >= 4) {
            // lisnica dodaj dionica PLV-R-A 20 107.30
            // lisnica dodaj obveznica RH-MF007 100 95.00 1000.00
            if (this->argc < 6) {
                throw invalid_argument("Neispravan unos za dodavanje!");
            }
            string tip = this->argv[2];
            string oznaka = this->argv[3];
            int kolicina = stoi(this->argv[4]);
            double cijena = stod(this->argv[5]);
            if (tip == "dionica" && argc == 6) {
                int kolicina = stoi(this->argv[4]);
                double cijena = stod(this->argv[5]);
                this->lisnica->dodajDionicu(cijena, kolicina, oznaka);
            }
            else if (tip == "obveznica" && argc == 7) {
                double nominala = stod(this->argv[6]);
                this->lisnica->dodajObveznicu(oznaka, cijena, kolicina, nominala);
            }
            else {
                throw invalid_argument("Neispravan unos za dodavanje!");
            }
            return;
        }
        
        if (naredba == "izbaci" && argc == 3) {
            bool uspio = this->lisnica->izbaciVrijednosniPapir(argv[2]);
            if (!uspio) {
                throw invalid_argument("");
            }
            return;
        }

        throw invalid_argument("Neispravana komanda!");
	}
}