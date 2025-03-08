#include "Obveznica.h"

namespace markot4 {
    Obveznica::Obveznica(string oznaka) : VrijednosniPapir(oznaka) {}
    Obveznica::Obveznica(string oznaka, double cijena) : VrijednosniPapir(oznaka, cijena) {}

    void Obveznica::postaviCijenu(double novaCijena) {
        VrijednosniPapir::postaviCijenu(novaCijena);
    }

    double Obveznica::dohvatiCijenu() const {
        return VrijednosniPapir::dohvatiCijenu();
    }

    double Obveznica::izracunajVrijednost() {
        return VrijednosniPapir::izracunajVrijednost();
    }
}