#include "Dionica.h"
#include <sstream>
#include <iomanip> 

namespace markot4 {

    Dionica::Dionica(string oznaka) : VrijednosniPapir(oznaka) {}
    Dionica::Dionica(string oznaka, int kolicina, double cijena) : VrijednosniPapir(oznaka, kolicina, cijena) {}
    Dionica::Dionica(istream& from) {
        string line;
        from >> oznaka >> cijena >> kolicina;
        getline(from, line);
    }

    void Dionica::postaviCijenu(double novaCijena) {
        VrijednosniPapir::postaviCijenu(novaCijena);
    }

    double Dionica::dohvatiCijenu() const {
        return VrijednosniPapir::dohvatiCijenu();
    }

    double Dionica::izracunajVrijednost() {
        return cijena * kolicina;
    }

    void Dionica::toStream(ostream& to) {
        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << cijena;
        string formatirana_cijena = oss.str();

        to << "dionica " << oznaka << " " << formatirana_cijena << " " << kolicina;
    }

    bool Dionica::isObveznica() {
        return false;
    }

    bool Dionica::isDionica() {
        return true;
    }

    void Dionica::ispisToStream(ostream& to) {

        ostringstream oss;
        oss << std::fixed << std::setprecision(2) << cijena;
        string formatirana_cijena = oss.str();

        to << oznaka << " " << formatirana_cijena << " " << kolicina;
    }

    Dionica::~Dionica() {

    }


}