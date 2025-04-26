#include "LisnicaCommand.h"
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iomanip>

namespace markot4 {
	LisnicaCommand::LisnicaCommand(int argc, const char* argv[], LisnicaClass* lisnica) {
		this->lisnica = lisnica;
		this->argc = argc;
		for (int i = 0; i < argc; ++i) {
			this->argv.push_back(std::string(argv[i]));  // Pretvoara char* u std::string i dodajte u vektor
		}
	}

    void LisnicaCommand::vrijednostPapiraToStream(ostream& to) {
        string oznaka = this->argv[2];
        double vrijednost = this->lisnica->vrijPoVrijPapir(oznaka);

        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << vrijednost; // Formatira into the string stream
        string formatirana_vrijednost = oss.str();

        // Vrijednost PLV-R-A je 1520,73 Eur
        to << "Vrijednost " << oznaka << " "<< "je " << formatirana_vrijednost << " " << "Eur";
        return;
    }

    void LisnicaCommand::vrijednostDionicaToStream(ostream& to) {
        argc = this->argc;
        if (argc != 3) {
            throw invalid_argument("Arguement za vrijednost dionice je krivo napisan.");
        }
        double vrijednost = this->lisnica->sveDionice();

        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << vrijednost;
        string formatirana_vrijednost = oss.str();

        //Ukupna vrijednost svih dionica u lisnici je 15.372,16 Eur
        to << "Ukupna vrijednost svih dionica u lisnici je " << formatirana_vrijednost << " " << "Eur";
        return;
    }

    void LisnicaCommand::vrijednostObveznicaToStream(ostream& to) {
        argc = this->argc;
        if (argc != 3) {
            throw invalid_argument("Argument za vrijednost obveznice je krivo napisan.");
        }
        double vrijednost = this->lisnica->sveObveznice();

        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << vrijednost;
        string formatirana_vrijednost = oss.str();

        //Ukupna vrijednost svih obveznica u lisnici je 15.372,16 Eur
        to << "Ukupna vrijednost svih obveznica u lisnici je " << formatirana_vrijednost << " " << "Eur";
        return;
    }

    void LisnicaCommand::papiriToStream(ostream& to) {
        if (argc != 2) {
            throw invalid_argument("Arguement za sadrzaj je krivo napisan.");
        }
        this->lisnica->ispisToStream(to);
    }

    void LisnicaCommand::vrijednostLisniceToStream(ostream& to) {
        if (argc != 2) {
            throw invalid_argument("Arguement za lisnicu je krivo napisan.");
        }
        double vrijednost = this->lisnica->vrijednostCijeleLisnice();

        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << vrijednost;
        string formatirana_vrijednost = oss.str();

        to << "Ukupna vrijednost lisnice je " << formatirana_vrijednost << " " << "Eur";
    }

    void LisnicaCommand::promjenaCijena(string imeDatoteke) {
        if (argc != 4) {
            throw invalid_argument("Argument za promjenu cijene je krivo napisan.");
        }
        ifstream from(imeDatoteke);
        if (!from.is_open()) { 
            throw invalid_argument("Ne mogu citati iz datoteke");
        }
        int kulike = this->lisnica->promjenaCijene(from);
        cout << "Promijenjena cijena " << kulike << " vrijednosnih papira" << endl;
    }


    void LisnicaCommand::promjenaCijena(istream& from) {
        if (argc != 4) {
            throw invalid_argument("Argument za promjenu cijene je krivo napisan.");
        }
        this->lisnica->promjenaCijene(from);
    }

	void LisnicaCommand::process() {
        argc = this->argc;

        if (argc < 2) {
            throw invalid_argument("nedovoljno argumenata!");
        }
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
            if (oznaka == string("--datoteka")) {
                cout << "Citanje cijena iz datoteke: " << this->argv[3] << endl;
                this->promjenaCijena(this->argv[3]);
                return;
            }
            double novaCijena = stod(this->argv[3]);
            this->lisnica->promjenaCijene(novaCijena, oznaka);
            return;
        }

         if (naredba == "vrijednost" && argc == 3 && string(argv[2]) == "dionice") {
            this->vrijednostDionicaToStream(cout);
            return;
            //cout << "Ukupna vrijednost svih dionica je " << lisnica.sveDionice() << " EUR" << endl;
        }
        if (naredba == "vrijednost" && argc == 3 && string(argv[2]) == "obveznice") {
            //cout << "Ukupna vrijednost svih obveznica je " << lisnica.sveObveznice() << " EUR" << endl;
            this->vrijednostObveznicaToStream(cout);
            return;
        }

        if (naredba == "vrijednost" && argc == 3) {
            this->vrijednostPapiraToStream(cout);
            return;
        }

        if (naredba == "vrijednost" && argc == 2) {
            this->vrijednostLisniceToStream(cout);
            return;
        }

        if (naredba == "sadrzaj" && argc == 2) {
            this->papiriToStream(cout);
            return;
        }

        throw invalid_argument("Neispravna komanda!");
	}
}