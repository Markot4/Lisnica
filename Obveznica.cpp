#include "Obveznica.h"
#include <sstream>
#include <iomanip> 

namespace markot4 {
    Obveznica::Obveznica(std::string oznaka) : VrijednosniPapir(oznaka), nominalnaCijena(100){}
    Obveznica::Obveznica(std::string oznaka, double cijena, int kolicina, double nominalnaCijena) : VrijednosniPapir(oznaka, kolicina, cijena), nominalnaCijena(nominalnaCijena) {}
    Obveznica::Obveznica(std::istream& from) {
        std::string line;
        double cijena;
        from >> getOznaka() >> cijena >> kolicina >> nominalnaCijena;
        postaviCijenu(cijena);
        getline(from, line);
    }


    double Obveznica::izracunajVrijednost() {
        double cijena;
        return dohvatiCijenu() * nominalnaCijena * kolicina / 100;
    }

    void Obveznica::toStream(std::ostream& to) {

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << dohvatiCijenu();
        std::string formatirana_cijena = oss.str();

        std::ostringstream nominala_stream;
        nominala_stream << std::fixed << std::setprecision(2) << nominalnaCijena;
        std::string formatirana_nominala = nominala_stream.str();

        to << "obveznica " << getOznaka() << " " << formatirana_cijena << " " << kolicina << " " << formatirana_nominala;
    }

    bool Obveznica::isObveznica() {
        return true;
    }

    bool Obveznica::isDionica() {
        return false;
    }
    void Obveznica::ispisToStream(std::ostream& to) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << dohvatiCijenu();
        std::string formatirana_cijena = oss.str();

        std::ostringstream nominala_stream;
        nominala_stream << std::fixed << std::setprecision(2) << nominalnaCijena;
        std::string formatirana_nominala = nominala_stream.str();

        to << getOznaka() << " " << formatirana_cijena << " " << kolicina << " " << formatirana_nominala;
    }
    Obveznica::~Obveznica() {

    }
}