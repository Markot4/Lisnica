#include "Obveznica.h"
#include <sstream>
#include <iomanip> 

namespace markot4 {
    Obveznica::Obveznica(string oznaka) : VrijednosniPapir(oznaka), nominalnaCijena(100){}
    Obveznica::Obveznica(string oznaka, double cijena, int kolicina, double nominalnaCijena) : VrijednosniPapir(oznaka, kolicina, cijena), nominalnaCijena(nominalnaCijena) {}
    Obveznica::Obveznica(istream& from) {
        string line;
        from >> oznaka >> cijena >> kolicina >> nominalnaCijena;
        getline(from, line);
    }
    void Obveznica::postaviCijenu(double novaCijena) {
        VrijednosniPapir::postaviCijenu(novaCijena);
    }

    double Obveznica::dohvatiCijenu() const {
        return VrijednosniPapir::dohvatiCijenu();
    }

    double Obveznica::izracunajVrijednost() {
        return cijena * nominalnaCijena * kolicina / 100;
    }

    void Obveznica::toStream(ostream& to) {

        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << cijena;
        string formatirana_cijena = oss.str();

        ostringstream nominala_stream;
        nominala_stream << std::fixed << std::setprecision(2) << nominalnaCijena;
        string formatirana_nominala = nominala_stream.str();

        to << "obveznica " << oznaka << " " << formatirana_cijena << " " << kolicina << " " << formatirana_nominala;
    }

    bool Obveznica::isObveznica() {
        return true;
    }

    bool Obveznica::isDionica() {
        return false;
    }
    void Obveznica::ispisToStream(ostream& to) {
        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << cijena;
        string formatirana_cijena = oss.str();

        ostringstream nominala_stream;
        nominala_stream << std::fixed << std::setprecision(2) << nominalnaCijena;
        string formatirana_nominala = nominala_stream.str();

        to << oznaka << " " << formatirana_cijena << " " << kolicina << " " << formatirana_nominala;
    }
    Obveznica::~Obveznica() {

    }
}