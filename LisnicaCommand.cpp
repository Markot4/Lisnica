#include "LisnicaCommand.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

namespace markot4 {
	LisnicaCommand::LisnicaCommand(int argc, const char* argv[], LisnicaClass* lisnica) {
			this->lisnica = lisnica;
		this->argc = argc;
		for (int i = 0; i < argc; ++i) {
			this->argv.push_back(std::string(argv[i]));  // Convert char* to std::string and add to vector
		}
	}


    void LisnicaCommand::vrijednostPapiraToStream(ostream& to) {
        string oznaka = this->argv[2];
        double vrijednost = this->lisnica->vrijPoVrijPapir(oznaka);

        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << vrijednost; // Format into the string stream
        string formatirana_vrijednost = oss.str();

        // Vrijednost PLV-R-A je 1520,73 Eur
        to << "Vrijednost " << oznaka << " "<< "je " << formatirana_vrijednost << " " << "Eur";
        return;
    }

    void LisnicaCommand::vrijednostDionicaToStream(ostream& to) {
        double vrijednost = this->lisnica->sveDionice();

        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << vrijednost;
        string formatirana_vrijednost = oss.str();

        //Ukupna vrijednost svih dionica u lisnici je 15.372,16 Eur
        to << "Ukupna vrijednost svih dionica u lisnici je " << formatirana_vrijednost << " " << "Eur";
        return;
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
                bool uspio = this->lisnica->dodajDionicu(cijena, kolicina, oznaka);
                if (!uspio) {
                    throw invalid_argument("Dionica vec postoji");
                }
            }
            else if (tip == "obveznica" && argc == 7) {
                double nominala = stod(this->argv[6]);
                bool uspio = this->lisnica->dodajObveznicu(oznaka, cijena, kolicina, nominala);
                if (!uspio) {
                    throw invalid_argument("Obveznica vec postoji");
                }
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

        if (naredba == "kolicina" && argc == 4) {
            string oznaka = this->argv[2];
            int promjena = stoi(this->argv[3]);
            this->lisnica->promjenaKolicine(promjena, oznaka);
            return;
        }

        if (naredba == "cijena" && argc == 4) {
            string oznaka = this->argv[2];
            double novaCijena = stod(this->argv[3]);
            this->lisnica->promjenaCijene(novaCijena, oznaka);
            return;
        }

        if (naredba == "vrijednost" && argc == 3) {
            this->vrijednostPapiraToStream(cout);
            return;
        }

        if (naredba == "vrijednost" && argc == 3 && string(argv[2]) == "dionice") {
            this->vrijednostDionicaToStream(cout);
            //cout << "Ukupna vrijednost svih dionica je " << lisnica.sveDionice() << " EUR" << endl;
        }

        throw invalid_argument("Neispravana komanda!");
	}
}