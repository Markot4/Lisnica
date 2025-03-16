#include "Dionica.h"
#include <iomanip> 

namespace markot4 {

    Dionica::Dionica(string oznaka) : VrijednosniPapir(oznaka) {}
    Dionica::Dionica(string oznaka, int kolicina, double cijena) : VrijednosniPapir(oznaka, kolicina, cijena) {}

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
        to << "dionica " << oznaka << " " << fixed << setprecision(2)  << cijena << " " << kolicina;
    }

    bool Dionica::isObveznica() {
        return false;
    }

    bool Dionica::isDionica() {
        return true;
    }

    Dionica::~Dionica() {

    }
}