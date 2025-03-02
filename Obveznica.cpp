#include "Obveznica.h"

namespace markot4 {
    Obveznica::Obveznica(string oznaka) : VrijednosniPapir(oznaka) {}
    Obveznica::Obveznica(string oznaka, double cijena, int kolicina, double nominalnaCijena) : VrijednosniPapir(oznaka, kolicina, cijena), nominalnaCijena(nominalnaCijena) {}

    void Obveznica::postaviCijenu(double novaCijena) {
        VrijednosniPapir::postaviCijenu(novaCijena);
    }

    double Obveznica::dohvatiCijenu() const {
        return VrijednosniPapir::dohvatiCijenu();
    }

    double Obveznica::izracunajVrijednost() {
        return cijena * nominalnaCijena;
    }
}